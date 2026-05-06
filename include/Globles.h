#ifndef Globles_h
#define Globles_h

#include <Buttons.h>
#include <iostream>
#include <vector>
#include <SDL3/SDL.h>

namespace Globles
{
 extern bool IsRunning;

 extern SDL_Window* MainWindow;
 extern SDL_Renderer* MainWindowRender;
 extern std::vector<CalculatorButtons> G_Buttons_L;
 extern TTF_Font* Font;
 extern char* CurrentExpression;
};

#endif

// void (**_Buttons)() = (void(**)())malloc(sizeof(void**)*10);
