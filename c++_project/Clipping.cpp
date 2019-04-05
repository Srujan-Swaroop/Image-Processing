#include <iostream>
#include"Clipping.h"

using namespace std;

Clipping::Clipping(){}
Clipping::Clipping(Image input,Image clip):Image(input.get_w(),input.get_h())
{

  for(int i=0;i<get_h();i++)
        for(int j=0;j<get_w();j++)
                           {
            Color c(255,255,255);
            Pixel p(i,j,c);
            this->set_p(p,i,j);
        }
  for(int i=0;i<get_h();i++)
        for(int j=0;j<get_w();j++)
        {
            if(clip.get_p(i,j).get_c().get_r()==255&&clip.get_p(i,j).get_c().get_g()==255&&clip.get_p(i,j).get_c().get_b()==255)
            {
                Color c(input.get_p(i,j).get_c().get_r(),input.get_p(i,j).get_c().get_g(),input.get_p(i,j).get_c().get_b());
            Pixel p(i,j,c);
            this->set_p(p,i,j);
            }
        }
}
Clipping::~Clipping(){}
