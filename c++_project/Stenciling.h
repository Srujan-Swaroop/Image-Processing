#ifndef STENCILING_H
#define STENCILING_H
#include "Image.h"
#include<iostream>
class Stenciling:public Image
{
public:
Stenciling();
Stenciling(Image input,Image clip);
~Stenciling();

};
#endif
