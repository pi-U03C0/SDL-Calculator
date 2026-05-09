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
      Globles::ExpressionLabel -> text = Globles::CurrentExpression;
      SDL_Event_Append();
      printf("Events Leght: %lld\n",Globles::Events.size());
      SDL_Event_H();
      Sleep(10);
    }

    return 0;
}
