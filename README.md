A SDL Calculator Write in C++

# Compile Time Options
[print_window_size_on_z]: print window size when "z" is press
[reset_window_size_button]: add a button under the Clear(C) Button which reset the window size to the init window size
[print_key]: print the what key is down
[TEST]: disable the main function in main.cpp and enable the main function in test.cpp
[verbose]: print verbose

expamles:
   ```powershell
   .\build.ps1 -RunExe -D "reset_window_size_button" -CoreConuter 10
   ```
this will Compile the prigrame with a extra button outside the initly window size
