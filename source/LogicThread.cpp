#pragma GCC diagnostic ignored "-Wunused-parameter"

#include "EventHandler.h"
#include "Globles.h"
#include "SDL3/SDL_events.h"
#include <cstdio>
#include <synchapi.h>
#include <windows.h>

DWORD WINAPI LogicThread_ThreadMain(LPVOID lpParam)
{
    while (Globles::IsRunning)
    {
      if (strcmp(Globles::ExpressionLabel -> text, Globles::CurrentExpression))
      {
        int str_w;
        TTF_GetStringSize(Globles::Font, " ", 1 , &str_w, NULL);
        Globles::ExpressionLabel -> offset_x -= str_w*2;

        Globles::ExpressionLabel -> text = Globles::CurrentExpression;
      }

      SDL_Event_H();
      Sleep(10);
    }

    return 0;
}

   
