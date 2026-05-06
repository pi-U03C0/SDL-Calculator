#include "SDL3/SDL_video.h"
#include <cstdio>
#include <iostream>
#include <SDL3/SDL.h>
#include <Globles.h>
#include <render.h>

namespace Globles
{
  bool IsRunning = false;
  SDL_Window* MainWindow = NULL;
  SDL_Renderer* MainWindowRender = NULL;
  std::vector<CalculatorButtons> G_Buttons_L;
  TTF_Font* Font = NULL;
  char* CurrentExpression = NULL;
};

int init()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        printf("SDL_Init Error: %s\n", SDL_GetError()); return 1;
        return 1;
    }

    if (!TTF_Init())
    {
      printf("SDL_TTF Error: %s\n",SDL_GetError());
      return 1;
    }

    Globles::MainWindow = SDL_CreateWindow( "Calculator", 600, 600, SDL_WINDOW_RESIZABLE);
    if (!Globles::MainWindow)
    {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    Globles::MainWindowRender = SDL_CreateRenderer(Globles::MainWindow,NULL);
    if (!Globles::MainWindowRender)
    {
        printf("Renderer Error: %s\n", SDL_GetError());

        SDL_DestroyWindow(Globles::MainWindow);
        SDL_Quit();

        return 1;
    }

    Globles::Font = TTF_OpenFont("c:/Windows/Fonts/arial.ttf", 15);

    return 0;
}

void Quit()
{
    SDL_DestroyRenderer( Globles::MainWindowRender);
    SDL_DestroyWindow( Globles::MainWindow);

    TTF_Quit();
    SDL_Quit();
}

#ifndef TEST
int main(int argc, char **argv)
{
    for (int i = 0 ; argc > i ; i++)
    {
      printf("argv[%d] = %s\n",i,argv[i]);
    }

    if (init() != 0)
    {
      return 1;
    }

    Globles::IsRunning = true;

    gmain();;

    Quit();

    return 0;
}
#endif
