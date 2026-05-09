#Function Names:
#         ClearFile
#         Compile-Source
#         SetUp-SDL

param
(
   [Parameter(Mandatory=$false, ValueFromPipeline=$true)]
   [switch]$ClearFile,

   [Parameter(Mandatory=$false, ValueFromPipeline=$true)]
   [switch]$Test,

   [Parameter(Mandatory=$false, ValueFromPipeline=$true)]
   [string[]]$D,

   [Parameter(Mandatory=$false, ValueFromPipeline=$true)]
   [switch]$RunExe,

   [Parameter(Mandatory=$false, ValueFromPipeline=$true)]
   [int]$CoreConuter = 3,

   [Parameter(Mandatory=$false, ValueFromPipeline=$true)]
   [switch]$ComMainExe
)

$OWD = Split-Path $MyInvocation.MyCommand.Path
$SOURCE = "$OWD/source"
$BIN = "$OWD/bin"
$LIB = "$OWD/Lib"
$INCLUDE = "$OWD/include"

$CFLAG = @("-Wall","-Wextra")
$CFLAGI = @("-Wno-unused-parameter","-Wno-sign-compare","-Wno-missing-field-initializers","-Wno-cast-function-type")

$SDLDLLP = "$BIN/SDL3.dll"
$SDL_TTFDLLP = "$BIN/SDL3_ttf.dll"

$Verbose = $false
$CompileMainExe = $true
$EXENAME = "main"

function ClearFile
{
  remove-item -r $BIN/*
}

function Compile-Source
{
  Write-Host "Compileing Source"

  if (-not (Test-Path -Path "$BIN/Source"))
  {
    mkdir "$BIN/Source" | Out-Null
  }
  $SOURCE_OBJ = (ls -name -Path "$SOURCE/*.cpp")
  $DidError = $false

  $Results = $SOURCE_OBJ | ForEach-Object -Parallel {
    Write-Host "SRC: Source/$_ -> bin/$_.o"

    if ($using:Verbose)
    {
      Write-Host "g++ -o $using:BIN/Source/$_.o -c  $using:SOURCE/$_ -I$using:INCLUDE $using:CFLAG"
    }

    & "g++" "-o" "$using:BIN/Source/$_.o" "-c" "$using:SOURCE/$_" "-I$using:INCLUDE" $using:CFLAG
    return ($LASTEXITCODE -ne 0)

  } -ThrottleLimit $CoreConuter

  $DidError = $Results -contains $true
  return (-not ($DidError))
}

function SetUp-SDL
{
  if (-not($SDLDLLP))
  {
    Copy-Item "$LIB/SDL3.dll" $SDLDLLP
    Copy-Item "$LIB/SDL3_ttf.dll" $SDL_TTFDLLP
  }
}

if ($PSCmdlet.MyInvocation.BoundParameters["Verbose"].IsPresent)
{
  $Verbose = $true
  echo "Verbose"
}

if ($D.Length -ne 0)
{
  $D | ForEach-Object {
    $CFLAG += "-D$_"
  }
}

if ($Test)
{
  $CFLAG += "-DTEST"
}

if ($IsSource)
{
  return
}

if (-not (Test-Path -Path "$BIN"))
{
  mkdir $BIN | Out-Null
}

if ($PSBoundParameters.ContainsKey("ClearFile"))
{
  if ($ClearFile -eq "ns")
  {
    $CompileMainExe = $true
  }
  else
  {
    $CompileMainExe = $false
  }
  ClearFile
}

if ((Test-Path -path $BIN) -eq $false) 
{
  mkdir $BIN | Out-Null
}

if ($ComMainExe)
{
  $CompileMainExe = $true
}

if ($CompileMainExe)
{
  if (-not (Compile-Source))
  {
    Write-Host "Error Compileing Source"
    exit
  }

  $SOURCE_OBJ =$((ls -name -Path "$BIN/Source/*.o") | ForEach-Object {
    echo "$BIN/Source/$_"
  })

  if ($Verbose)
  {
    Write-Host "g++ -o $BIN/$EXENAME.exe $SOURCE_OBJ -L$LIB -lSDL3 -lSDL3_ttf"
  }

  Write-Host "EXE: -> bin/$EXENAME.exe"

  & "g++" "-o" "$BIN/$EXENAME.exe" $SOURCE_OBJ  "-L$LIB" "-lSDL3" "-lSDL3_ttf" $CFLAG

  if ($?)
  {
    SetUp-SDL
    if ($RunExe)
    {
      & "$BIN/$EXENAME.exe"
      $Message = "`e[32mSUCCESS`e[0m"
      if ($LASTEXITCODE -eq -1073741819)
      {
        $Message = "`e[31mSEGSEVG`e[0m"
      }
      if ($LASTEXITCODE -eq -1073741795)
      {
        $Message = "`e[31mILLEGAL INSTRUCTION`e[0m"
      }
      Write-Host "`nLASTEXITCODE: $LASTEXITCODE $Message" -nonewline
    }
  }
}
