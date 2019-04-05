#include "Generateforone.h"
#include<iostream>
#include<math.h>
bool israd(int x1,int y1,int x2,int y2,float rad)
{
    return ((pow(x1-x2,2))+(pow((y1-y2),2)))<=(pow(rad,2));
}
void Generateforone::createcircle(int x,int y,float rad)
{
    for(int i=0;i<get_h();i++)
        for(int j=0;j<get_w();j++)
            if(israd(x,y,i,j,rad))
            {
            Color c(255,255,255);
            Pixel p(i,j,c);
            this->set_p(p,i,j);
            }
}
Generateforone::Generateforone()
{}
Generateforone::~Generateforone()
{
}
Generateforone::Generateforone(int w,int h):Image(w,h)
{

    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        {
          Color c(0,0,0);
          Pixel p(i,j,c);
           this->set_p(p,i,j);
        }
   float rad=min(floor(0.125*w),floor(0.125*h));
   createcircle(floor(0.5*w),floor(0.5*h),rad);

   rad=min(floor(0.125*w/2.0),floor(0.125*h/2.0));

   createcircle(floor(0.25*w),floor(0.25*h),rad);
   createcircle(floor(0.25*w),floor(0.75*h),rad);
   createcircle(floor(0.75*w),floor(0.25*h),rad);
   createcircle(floor(0.75*w),floor(0.75*h),rad);
}
