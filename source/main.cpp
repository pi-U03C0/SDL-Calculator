#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <SDL3/SDL.h>
#include <Globles.h>
#include <render.h>
#include <LogicThread.h>
#include <string.h>
#include <vector>
#include <windows.h>

namespace Globles
{
  bool IsRunning = false;
  SDL_Window* MainWindow = NULL;
  SDL_Renderer* MainWindowRender = NULL;
  std::vector<CalculatorButtons> G_Buttons_L;
  TTF_Font* Font = NULL;
  char* CurrentExpression = (char*)malloc(1024);
  CalculatorLabel* ExpressionLabel = NULL;
  DWORD LogicThread_DWORD = 0;
  HANDLE LogicThread_HANDLE = NULL;
  std::vector<SDL_Event> Events;
  std::mutex EventLock;
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

    Globles::MainWindow = SDL_CreateWindow( "Calculator", INIT_WINDOW_SCREEN_SIZE_W, INIT_WINDOW_SCREEN_SIZE_H, SDL_WINDOW_RESIZABLE);
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

    Globles::CurrentExpression = strdup("0");

    return 0;
}

void Quit()
{
    SDL_DestroyRenderer(Globles::MainWindowRender);
    SDL_DestroyWindow(Globles::MainWindow);

    TTF_Quit();
    SDL_Quit();
}

inline void StartLogicThread()
{
  Globles::LogicThread_HANDLE = CreateThread(NULL, 0, LogicThread_ThreadMain, NULL, 0, &Globles::LogicThread_DWORD);
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

    StartLogicThread();

    gmain();;

    WaitForSingleObject(Globles::LogicThread_HANDLE, INFINITE);

    Quit();

    return 0;
}
#endif
