#ifndef Task5_H_
#define  Task5_H_

#include "Image.h"
#include <iostream>

using namespace std;
class Task5:public Image
{
public:
    Task5();
    ~Task5();
    Task5(int w,int h);
    void convert1(Image image);
    void convert2(Image image);
};
#endif
