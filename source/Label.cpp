#include "Buttons.h"
#include "render.h"
#include <Label.h>
#include <Globles.h>
#include <cstdio>
#include <exception>
#include <sec_api/stdio_s.h>

CalculatorLabel::CalculatorLabel(char* text,int x,int y,int w,int h,SDL_Color fg,SDL_Color bg,int offset_x,int offset_y)
{
  this -> text = text;
  this -> x = x;
  this -> y = y;
  this -> w = w;
  this -> h = h;
  this -> fg = fg;
  this -> bg = bg;
  this -> offset_x = offset_x;
  this -> offset_y = offset_y;

}

void CalculatorLabel::render()
{
  SDL_DrawRect(this -> x,this -> y,this -> h,this -> w,DEPACK_SDL_COLOUR_INT(this -> bg),true);
  SDL_DrawRect(this -> x,this -> y,this -> h,this -> w,0,0,0,255,false);
  SDL_DrawText(this -> text, this -> x + this -> offset_x, this -> y + this -> offset_y, DEPACK_SDL_COLOUR_INT(this -> fg));
}
