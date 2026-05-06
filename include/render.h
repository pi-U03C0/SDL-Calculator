#ifndef render_h
#define render_h

#include "SDL3/SDL_render.h"

#define ClearScreen(r,g,b,a) SDL_SetRenderDrawColor(Globles::MainWindowRender,r,g,b,a); SDL_RenderClear(Globles::MainWindowRender);

void gmain();

void SDL_DrawRect(float x,float y,float h,float w,float r,float g,float b,float a=255,bool fill=true);

void SDL_DrawText(char* text,float x,float y,Uint8 r,Uint8 g,Uint8 b,Uint8 a=255,char size=0);

#endif
