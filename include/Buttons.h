#pragma once

#ifndef Buttons_H
#define Buttons_H

class CalculatorButtons
{
  public:
     int x;
     int y;

     float h;
     float w;

     float r;
     float g;
     float b;
     float a = 255;

     char* text;
     void (*callback)(CalculatorButtons*);

  CalculatorButtons(char* text,void (*callback)(CalculatorButtons*),int x, int y, int h, int w, int r, int g, int b,int a=100);

  void Render();
  bool check_and_run(float x,float y);
  bool check(float x,float y);
  void run();
};

#endif
