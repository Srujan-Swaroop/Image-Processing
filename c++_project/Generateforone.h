#ifndef GENERATEFORONE_H
#define GENERATEFORONE_H
#include "Image.h"
#include<iostream>

using namespace std;
class Generateforone:public Image
{
public:
Generateforone();
Generateforone(int w,int h);
~Generateforone();
void createcircle(int x,int y,float rad);
};
#endif
