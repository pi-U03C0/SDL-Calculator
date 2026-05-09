#include "Buttons.h"
#include "render.h"
#include <Label.h>
#include <Globles.h>
#include <exception>

CalculatorLabel::CalculatorLabel(char* text,int x,int y,int w,int h,SDL_Color fg,SDL_Color bg)
{
  this -> text = text;
  this -> x = x;
  this -> y = y;
  this -> w = w;
  this -> h = h;
  this -> fg = fg;
  this -> bg = bg;
}

void CalculatorLabel::render()
{
  SDL_DrawRect(this -> x,this -> y,this -> h,this -> w,DEPACK_SDL_COLOUR_INT(this -> bg),true);
  SDL_DrawRect(this -> x,this -> y,this -> h,this -> w,0,0,0,255,false);
  SDL_DrawText(this -> text, this -> x, this -> y, DEPACK_SDL_COLOUR_INT(this -> fg));

}
