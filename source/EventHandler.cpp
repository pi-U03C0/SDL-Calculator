#include "SDL3/SDL.h"
#include <EventHandler.h>
#include <render.h>
#include <cstdio>
#include <Globles.h>

void Key_Event_H(SDL_KeyboardEvent key)
{
    printf("Key(%d)\n", key.key);

    if (key.key == SDLK_ESCAPE) Globles::IsRunning = false;
    if (key.key == SDLK_F11) SDL_SetWindowFullscreen(Globles::MainWindow, true);
}

void Mouse_Event_H(SDL_MouseButtonEvent mouse_H)
{
    for (int i = 0; i < (int)Globles::G_Buttons_L.size() ; i++)
    {
      Globles::G_Buttons_L[i].check_and_run(mouse_H.x, mouse_H.y);
    }
}

int SDL_Event_H()
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
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
  }
  return 0;
}

