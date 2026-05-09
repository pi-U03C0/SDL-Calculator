#ifndef LABEL_H
#define LABEL_H

#include "SDL3/SDL_pixels.h"
#include <SDL3/SDL.h>

class CalculatorLabel
{
  public:
    int x;
    int y;
    int w;
    int h;
    SDL_Color fg;
    SDL_Color bg;
    char* text;

  CalculatorLabel(char* text,int x,int y,int w,int h,SDL_Color fg,SDL_Color bg);
  void render();
};
#endif
