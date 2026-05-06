#include "Globles.h"
#include "SDL3/SDL3_ttf/SDL_ttf.h"
#include <Buttons.h>
#include <cstdio>
#include <cstring>
#include <render.h>
#include <SDL3/SDL.h>
#include <winerror.h>

CalculatorButtons::CalculatorButtons(char* text,void (*callback)(char*),int x, int y, int h, int w, int r, int g, int b,int a)
{
    this->text = text;
    this -> x = x;

    this -> y = y;
    this -> h = h;

    this -> w = w;
    this -> r = r;

    this -> g = g;
    this -> b = b;

    this -> a = a;
    this -> callback = callback;
}

void CalculatorButtons::Render()
{
  int text_x = ((this -> x + (this -> w / 2)) - TTF_GetFontSize(Globles::Font) / 2) - strlen(this -> text);
  int text_y = ((this -> y + (this -> h / 2)) - TTF_GetFontSize(Globles::Font) / 2) - strlen(this -> text);

  SDL_DrawRect(this -> x, this -> y, this -> h, this -> w, this -> r, this -> g, this -> b, this -> a);
  SDL_DrawRect(this -> x,this -> y,this -> h,this -> w,0,0,0,255,false);
  SDL_DrawText(this -> text,text_x,text_y,255,255,255);
}

void CalculatorButtons::check_and_run(float x,float y)
{
  if ((x >= this -> x && x <= (this -> x + this -> w)) && (y >= this -> y && y <= (this -> y + this -> h)))
  {
    this -> callback(this -> text);
  }
  return;
}

// void (**_Buttons)() = (void(**)())malloc(sizeof(void**)*10);
