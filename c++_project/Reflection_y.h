#ifndef REFLECTION_Y_H
#define REFLECTION_Y_H
#include "Image.h"
#include<iostream>

using namespace std;

class Reflection_y : public Image
{
  public:
    Reflection_y();
    ~Reflection_y();
    Reflection_y(Image i);
};

#endif
