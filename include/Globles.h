#ifndef Globles_h
#define Globles_h

#include "Label.h"
#include <Buttons.h>
#include <iostream>
#include <vector>
#include <SDL3/SDL.h>

#define INIT_WINDOW_SCREEN_SIZE_W 230
#define INIT_WINDOW_SCREEN_SIZE_H 250

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
};

#endif

