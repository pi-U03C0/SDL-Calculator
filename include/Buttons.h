#pragma once

#ifndef Buttons_H
#define Buttons_H

class CalculatorButtons
{
  public:
     float x;
     float y;
     float h;
     float w;
     float r;
     float g;
     float b;
     float a = 255;
     char* text;
     void (*callback)(char*);

  CalculatorButtons(char* text,void (*callback)(char*),int x, int y, int h, int w, int r, int g, int b,int a=100);

  void Render();
  void check_and_run(float x,float y);
};

#endif
