#pragma once

#ifndef EvnetHandler_H
#define EvnetHandler_H

#include "SDL3/SDL_events.h"
void Key_Event_H(SDL_KeyboardEvent key);

void Mouse_Event_H(SDL_MouseButtonEvent mouse_H);
void SDL_Event_H();
void SDL_Event_Append();
#endif
