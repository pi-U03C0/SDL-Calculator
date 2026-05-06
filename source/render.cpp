#include "SDL3/SDL3_ttf/SDL_ttf.h"
#include "SDL3/SDL_oldnames.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_stdinc.h"
#include <SDL3/SDL.h>
#include <Globles.h>
#include <memory>

void  SDL_DrawRect(float x,float y,float h,float w,float r,float g,float b,float a=255,bool fill=true)
{
  SDL_SetRenderDrawColor(Globles::MainWindowRender,r,g,b,a);
  SDL_FRect maco_temp_var_rect = {x,y,w,h};
  if (fill)
  {
    SDL_RenderFillRect(Globles::MainWindowRender, &maco_temp_var_rect);
    return;
  }
  SDL_RenderRect(Globles::MainWindowRender, &maco_temp_var_rect);
}

void SDL_DrawText(char* text,float x,float y,Uint8 r,Uint8 g,Uint8 b,Uint8 a=255,char size=0)
{
    if (size == 0)
    {
      size = TTF_GetFontSize(Globles::Font);
    }

    TTF_SetFontSize(Globles::Font, size);

    SDL_Surface* surface = TTF_RenderText_Blended( Globles::Font, text, 0, (SDL_Color){r,g,b,a});

    SDL_Texture* texture = SDL_CreateTextureFromSurface( Globles::MainWindowRender, surface);

    SDL_FRect rect = { x, y, (float)surface->w, (float)surface->h };

    SDL_DestroySurface(surface);

    SDL_SetRenderDrawColor(Globles::MainWindowRender, 0,0,0,255);

    SDL_RenderTexture(Globles::MainWindowRender, texture, NULL, &rect);

    SDL_DestroyTexture(texture);

}

