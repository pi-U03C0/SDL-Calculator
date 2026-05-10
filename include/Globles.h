#ifndef Globles_h
#define Globles_h

#include "EventHandler.h"
#include "Label.h"
#include "SDL3/SDL_events.h"
#include <Buttons.h>
#include <mutex>
#include <thread>
#include <vector>
#include <SDL3/SDL.h>
#include <windows.h>

#define INIT_WINDOW_SCREEN_SIZE_W 230
#define INIT_WINDOW_SCREEN_SIZE_H 290

typedef void ((*RenderFunctions)());
typedef void ((*KeyMap)(int));

namespace Globles
{
 extern bool IsRunning;
 extern SDL_Window* MainWindow;
 extern SDL_Renderer* MainWindowRender;
 extern std::vector<CalculatorButtons> G_Buttons_L;
 extern TTF_Font* Font;
 extern char* CurrentExpression;
 extern CalculatorLabel* ExpressionLabel;
 extern std::vector<KeyMap> KeyMaps;
 extern DWORD LogicThread_DWORD;
 extern HANDLE LogicThread_HANDLE;
 extern std::vector<SDL_Event> Events;
 extern std::mutex EventLock;
};

#endif

