#include "Buttons.h"
#include <Globles.h>
#include <cstdio>
#include <SDL3/SDL.h>
#include <EventHandler.h>
#include <cstdlib>
#include <functional>
#include <future>
#include <render.h>

void operator_check(char* B_text)
{
  printf("callback text: %s\n",B_text);
}

void RenderButtons()
{
  for (int i = 0; i < (int)Globles::G_Buttons_L.size() ; i++)
  {
    Globles::G_Buttons_L[i].Render();
  }
}

void RenderExpression()
{

}

void gmain_render()
{
  RenderButtons();
  RenderExpression();
}

void gmain()
{
    CalculatorButtons button_add = CalculatorButtons((char*)"add",operator_check,10,10,30,50,200,100,200,100);
    CalculatorButtons button_sub = CalculatorButtons((char*)"sub",operator_check,100,100,30,50,200,100,200,100);
    CalculatorButtons button_div = CalculatorButtons((char*)"mul",operator_check,200,200,30,50,200,100,200,100);
    CalculatorButtons button_mul = CalculatorButtons((char*)"div",operator_check,300,200,30,50,200,100,200,100);
    CalculatorButtons button_one = CalculatorButtons((char*)"one",operator_check,400,200,30,50,200,100,200,100);

    Globles::G_Buttons_L.push_back(button_sub);
    Globles::G_Buttons_L.push_back(button_div);
    Globles::G_Buttons_L.push_back(button_mul);
    Globles::G_Buttons_L.push_back(button_one);

    while (Globles::IsRunning)
    {
        ClearScreen(0,100,255,255);

        SDL_Event_H();

        gmain_render();

        SDL_RenderPresent( Globles::MainWindowRender);
    }
}
