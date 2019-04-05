#ifndef CLIPPING_H
#define CLIPPING_H
#include "Image.h"
#include<iostream>
class Clipping:public Image
{
public:
Clipping();
Clipping(Image input,Image clip);
~Clipping();

};
#endif
