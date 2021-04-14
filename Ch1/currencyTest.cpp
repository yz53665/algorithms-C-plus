#include "currency.h"
#include "illegalParameterValue.h"
#include <iostream>


int main()
{
  currency h(plus, 3, 50);
  currency g, i, j;

  g.setValue(minus, 2, 25);
  i.setValue(-6.45);

  j = h + g;
  std::cout << j << "=" << h << "+" << g << std::endl;

  j = i + g + h;
  std::cout << i << '+' << g << '+' << h << '=' << j << std::endl;

  std::cout << "increment" << i << "by" << g
            << "and then add " << i << std::endl;


  std::cout << "attempt to inalize cents with 152" << std::endl;
  try {
    i.setValue(plus, 3, 152);
  } catch (illegalParameterValue e) {
    std::cout << "catch thrown exception" << std::endl;
    e.outputMessage();
  }

  return 0;
}

