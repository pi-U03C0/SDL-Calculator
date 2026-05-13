#pragma GCC diagnostic ignored "-Wunused-parameter"

#include "Operator.h"
#include "Globles.h"
#include "Util.h"
#include <cstdio>

void operator_clear(CalculatorButtons* cal_b)
{
    Globles::ExpressionLabel -> text = (char*)"0";
    Globles::CurrentExpression = (char*)"0";
    Globles::ExpressionLabel -> offset_x = INIT_LABEL_TEXT_OFFSET_X;
    return;
}

void operator_add_text(CalculatorButtons *cal_b)
{
  Globles::CurrentExpression = stradd(Globles::CurrentExpression,cal_b -> text);
}

void operator_back(CalculatorButtons *cal_b)
{
  if (!strcmp(Globles::CurrentExpression, "0"))
  {
    printf("back 0 == Globles::CurrentExpression\n");
    return;
  }
  printf("Globles::CurrentExpression = %s\n",Globles::CurrentExpression);

  for (size_t i = 0 ; i < strlen(Globles::CurrentExpression) ; i++)
  {
    printf("Globles::CurrentExpression[%llu] = %c\n",i,Globles::CurrentExpression[i]);
  }
}
