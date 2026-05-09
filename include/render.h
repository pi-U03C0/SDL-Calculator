#ifndef render_h
#define render_h

#include <SDL3/SDL.h>

#define ClearScreen(r,g,b,a) SDL_SetRenderDrawColor(Globles::MainWindowRender,r,g,b,a); SDL_RenderClear(Globles::MainWindowRender);

#define DEPACK_SDL_COLOUR_INT(SDL_Color_S) SDL_Color_S.r,SDL_Color_S.g,SDL_Color_S.b,SDL_Color_S.a
#define PACK_SDL_COLOUR_INT(r,g,b) (SDL_Color){(Uint8)(r),(Uint8)(g),(Uint8)(b),(Uint8)(255)}

void gmain();

void SDL_DrawRect(float x,float y,float h,float w,float r,float g,float b,float a=255,bool fill=true);

void SDL_DrawText(char* text,float x,float y,Uint8 r,Uint8 g,Uint8 b,Uint8 a=255,char size=0);

#endif
