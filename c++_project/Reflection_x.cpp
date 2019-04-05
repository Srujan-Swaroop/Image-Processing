#include "Reflection_x.h"
#include <iostream>

using namespace std;

Reflection_x::Reflection_x(){}

Reflection_x::~Reflection_x(){}

Reflection_x::Reflection_x(Image i):Image(i.get_w(),i.get_h())
{
  int h = i.get_h();
  int w = i.get_w();
  for(int k = 0; k < _h/2; k++)
  {
      for(int j = 0; j < _w; j++)
      {
        Pixel a;
        a = i.get_p(k, j);
        Pixel b;
        b = i.get_p(h - k - 1, j);
        (*this).set_p(b, k, j);
        (*this).set_p(a, h - k - 1, j);
      }
  }
}
