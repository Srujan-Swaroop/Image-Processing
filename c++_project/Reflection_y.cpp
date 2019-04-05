#include "Reflection_y.h"
#include <iostream>

using namespace std;

Reflection_y::Reflection_y(){}

Reflection_y::~Reflection_y(){}

Reflection_y::Reflection_y(Image i):Image(i.get_w(),i.get_h())
{
  int h = i.get_h();
  int w = i.get_w();
  for(int k = 0; k < h; k++)
  {
      for(int j = 0; j < w; j++)
      {
        Pixel a;
        a = i.get_p(k, j);
        Pixel b;
        b = i.get_p(k, w-j-1);
        (*this).set_p(b, k, j);
        (*this).set_p(a, k, w-j-1);
      }
  }
}
