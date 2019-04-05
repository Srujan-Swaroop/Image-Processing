#include "Task5.h"
#include "Histogram.h"
#include "Reflection_x.h"
#include "Reflection_y.h"

#include <iostream>
using namespace std;


Task5::Task5(){}
Task5::~Task5(){}
Task5::Task5(int w,int h):Image(w,h)
{}
void Task5::convert1(Image image)
{
    Histogram h(image);
    vector<int >v=h.getThreshold();                 //get list of thresholds
        int mean=0;
        //cout<<v.size()<<endl;
        if(v.size()>=2)                          //if threshold size >2 then enter this loop
        {
            Color white(255,255,255);    //white r,g,b combination
            Color blue(0,0,255);        //blue r,g,b combination
            //cout<<v[0]<< " "<<v[1]<<endl;
            for(int i=0;i<_h;i++)
            {
                for(int j=0;j<_w;j++)
                {
                    mean=(image.get_p(i,j).get_c().get_r()+image.get_p(i,j).get_c().get_b()+image.get_p(i,j).get_c().get_g())/3;
                    if(mean>v[0])                                                //if pixel at i,j 's brightness >first element of threshold then set pixel color to be white
                    {
                        Pixel p(i,j,white);
                        set_p(p,i,j);
                    }
                    else                                                                //else pixel at i,j 's brightness <first element of threshold then set pixel color to be blue
                    {
                        Pixel p1(i,j,blue);
                        set_p(p1,i,j);
                    }
                }
            }
        }
        else                    //if there are no thresholds then find reflection w.r.t y-axis
        {
            //cout<<"REFLECTION"<<endl;
            Reflection_y r(image);
            for(int i=0;i<image.get_h();i++ )
            {
                for(int j=0;j<image.get_w();j++)
                {
                    Pixel p(i,j,r.get_p(i,j).get_c());
                    set_p(p,i,j);
                }
            }
        }
    }
void Task5::convert2(Image image)
{
    Histogram h(image);
    vector<int >v=h.getThreshold();                         //get list of thresholds
        int mean=0;
        if(v.size()>=2)                             //if threshold size >2 then enter this loop
        {
           Color white(255,255,255);                 //white r,g,b combination
		   Color blue(255,255,0);                           //yellow r,g,b combination
            for(int i=0;i<_h;i++)
            {
                for(int j=0;j<_w;j++)
                {
                    mean=(image.get_p(i,j).get_c().get_r()+image.get_p(i,j).get_c().get_b()+image.get_p(i,j).get_c().get_g())/3;
                    if(mean>v[1])                                        //if pixel at i,j 's brightness >secondelement of threshold then set pixel color to be white
                    {   
                        Pixel p(i,j,white);
                        set_p(p,i,j);
                    }
                    else                                                        //else pixel at i,j 's brightness <first element of threshold then set pixel color to be blue
                    {
                        Pixel p1(i,j,blue);
                        set_p(p1,i,j);
                    }
                }
            }
            // return (*this);
        }
        else                                                                             //if there are no thresholds then find reflection w.r.t y-axis
        {
            //cout<<"REFLECTION"<<endl;
            Reflection_x  r(image);
            for(int i=0;i<image.get_h();i++ )
            {
                for(int j=0;j<image.get_w();j++)
                {
                    Pixel p(i,j,r.get_p(i,j).get_c());
                    set_p(p,i,j);
                }
            }
        }
}
