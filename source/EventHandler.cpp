#include "SDL3/SDL.h"
#include "SDL3/SDL_events.h"
#include <EventHandler.h>
#include <mutex>
#include <render.h>
#include <cstdio>
#include <Globles.h>

void Key_Event_H(SDL_KeyboardEvent key)
{
  #ifdef print_key
  printf("key: %d",key.key);
  #endif

  if (key.key == SDLK_ESCAPE) Globles::IsRunning = false;
  if (key.key == SDLK_F11) SDL_SetWindowFullscreen(Globles::MainWindow, true);
}

void Mouse_Event_H(SDL_MouseButtonEvent mouse_H)
{
  #ifdef print_mouse_pos
  printf("mouse.x = %.2f,mouse.y = %.2f\n",mouse_H.x,mouse_H.y);
  #endif

  for (int i = 0; i < (int)Globles::G_Buttons_L.size() ; i++)
  {
    if (Globles::G_Buttons_L[i].check_and_run(mouse_H.x, mouse_H.y))
    {
      break;
    }
  }
}

void SDL_Event_H()
{
  for (SDL_Event event : Globles::Events)
  {
    switch (event.type)
    {
      case SDL_EVENT_QUIT:
      {
        Globles::IsRunning = false;
        break;
      }
      case SDL_EVENT_KEY_DOWN:
      {
        Key_Event_H(event.key);
        break;
      }
      case SDL_EVENT_MOUSE_BUTTON_DOWN:
      {
          Mouse_Event_H(event.button);
          break;
      }
    }
       Globles::Events.pop_back();
  }
}

void SDL_Event_Append()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_EVENT_QUIT)
    {
      Globles::IsRunning = false;
    }
    Globles::EventLock.lock();
    Globles::Events.push_back(event);
    Globles::EventLock.unlock();
  }
}
