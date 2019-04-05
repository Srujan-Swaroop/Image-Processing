#ifndef REFLECTION_X_H
#define REFLECTION_X_H
#include "Image.h"
#include<iostream>

using namespace std;

class Reflection_x : public Image
{
  public:
    Reflection_x();
    ~Reflection_x();
    Reflection_x(Image i);
};

#endif
