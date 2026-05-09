#include "Buttons.h"
#include "Label.h"
#include <Globles.h>
#include <SDL3/SDL.h>
#include <EventHandler.h>
#include <render.h>
#include <stdio.h>

void operator_check(CalculatorButtons* cal_b)
{
  printf("callback text: %s pos:(%d,%d)\n",cal_b -> text,cal_b -> x,cal_b -> y);
  Globles::CurrentExpression = cal_b -> text;
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
  if (Globles::ExpressionLabel == NULL)
  {
    return;
  }
  Globles::ExpressionLabel->render();
}

void gmain_render()
{
  RenderButtons();
  RenderExpression();
}

void add_buttons()
{
    CalculatorButtons button_1 = CalculatorButtons((char*)"1",operator_check,00,100,30,50,200,100,200,100);
    CalculatorButtons button_2 = CalculatorButtons((char*)"2",operator_check,60,100,30,50,200,100,200,100);
    CalculatorButtons button_3 = CalculatorButtons((char*)"3",operator_check,120,100,30,50,200,100,200,100);
    CalculatorButtons button_4 = CalculatorButtons((char*)"4",operator_check,00,140,30,50,200,100,200,100);
    CalculatorButtons button_5 = CalculatorButtons((char*)"5",operator_check,60,140,30,50,200,100,200,100);
    CalculatorButtons button_6 = CalculatorButtons((char*)"6",operator_check,120,140,30,50,200,100,200,100);
    CalculatorButtons button_7 = CalculatorButtons((char*)"7",operator_check,00,180,30,50,200,100,200,100);
    CalculatorButtons button_8 = CalculatorButtons((char*)"8",operator_check,60,180,30,50,200,100,200,100);
    CalculatorButtons button_9 = CalculatorButtons((char*)"9",operator_check,120,180,30,50,200,100,200,100);
    CalculatorButtons button_0 = CalculatorButtons((char*)"0",operator_check,60,220,30,50,200,100,200,100);

    CalculatorButtons button_add = CalculatorButtons((char*)"+",operator_check,180,100,30,50,100,100,200,100);
    CalculatorButtons button_sub = CalculatorButtons((char*)"sub",operator_check,180,140,30,50,100,100,200,100);
    CalculatorButtons button_div = CalculatorButtons((char*)"mul",operator_check,180,180,30,50,100,100,200,100);
    CalculatorButtons button_mul = CalculatorButtons((char*)"div",operator_check,180,220,30,50,100,100,200,100);

    CalculatorButtons button_equ = CalculatorButtons((char*)"=",operator_check,120,220,30,50,100,100,200,100);
    CalculatorButtons button_Clear = CalculatorButtons((char*)"C",operator_check,00,220,30,50,100,100,200,100);

    Globles::ExpressionLabel = new CalculatorLabel(Globles::CurrentExpression,0,0,230,90,PACK_SDL_COLOUR_INT(255,255,255),PACK_SDL_COLOUR_INT(100,200,100),200,60);

    Globles::G_Buttons_L.push_back(button_1);
    Globles::G_Buttons_L.push_back(button_2);
    Globles::G_Buttons_L.push_back(button_3);
    Globles::G_Buttons_L.push_back(button_4);
    Globles::G_Buttons_L.push_back(button_5);
    Globles::G_Buttons_L.push_back(button_6);
    Globles::G_Buttons_L.push_back(button_7);
    Globles::G_Buttons_L.push_back(button_8);
    Globles::G_Buttons_L.push_back(button_9);
    Globles::G_Buttons_L.push_back(button_0);

    Globles::G_Buttons_L.push_back(button_add);
    Globles::G_Buttons_L.push_back(button_sub);
    Globles::G_Buttons_L.push_back(button_div);
    Globles::G_Buttons_L.push_back(button_mul);

    Globles::G_Buttons_L.push_back(button_equ);
    Globles::G_Buttons_L.push_back(button_Clear);
}

void gmain()
{
    add_buttons();

    while (Globles::IsRunning)
    {
        ClearScreen(0,100,255,255);

        SDL_Event_Append();

        gmain_render();

        SDL_RenderPresent( Globles::MainWindowRender);
        SDL_Delay(100);
    }
}
