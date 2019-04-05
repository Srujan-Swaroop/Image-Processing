#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Histogram.h"
#include "Image.h"
#include "Color.h"
#include "Pixel.h"

using namespace std;

Histogram::Histogram(){}

Histogram::~Histogram(){}

Histogram::Histogram(Image i):brightness(i.get_h(), vector <int> (i.get_w())),histogram(256)          // memory assignment to brightness vector and histogram 
{
  int h = i.get_h();
  int w = i.get_w();
  for(int k = 0; k < h; k++)
  {
    for(int j = 0; j < w; j++)
    {
      Color c;
      c = i.get_p(k,j).get_c();
      brightness[k][j] = (c.get_r() + c.get_b() + c.get_g())/3;                //calculating brightness of each pixel
    }
  }
  for(int i = 0; i < h; i++)
  {
    for(int j = 0; j < w; j++)
    {
      histogram[brightness[i][j]]++;                        //calculating number of pixels of each brightness
    }
  }
int factor=4;                                                            //factor which decides how many elements to check for  minima adjacent to brightness of the element we are checking
vector <int> v;
  for(int i = factor; i < 256-factor; i++)
  {
      for(int j=1;j<=factor;j++)
      {
            v.push_back(histogram[i+j]);               //adding the next factor elements of the element we took
      }
      int f=modify(v);
      v.clear();
      for(int j=1;j<=factor;j++)
      {
            v.push_back(histogram[i-j]);              //adding the previous factor elements of the element we took
      }
      int h=modify(v);
      v.clear();
      if( f > histogram[i] && h >histogram[i])               //if histogram[i] is less than both minima then it is local minima so adiing to threshold list
      {
            threshold.push_back(i);
      }

  }
//   for(int j=1;j<255;j++)
//   {
//     if(histogram[j-1]>histogram[j] and histogram[j+1]>=histogram[j])
//     {
//       threshold.push_back(j);
//     }
//   }

}
int Histogram::modify(vector<int> v)      //finding the minimum in the given vector
{
      int min=v[0];
      for(int i=0;i<v.size();i++)
      {
            if(v[i]<min)
            {
                  min=v[i];
            }
      }
      return min;
}
vector<int> Histogram::getThreshold()            //returning threshold vector
{
  if(threshold.size()==0){
    cout << "No threshold\n";
  }
  return threshold;
}

vector< vector<int> > Histogram::getBrightness()       //returning brightness vector
{
  return brightness;
}

int Histogram::getMedianThreshold(){
	if(threshold.size()>0)
  	return threshold[threshold.size()/2];
	else{
		cout << "No threshold found\n";
		return 0;
	}
}

Image Histogram::picture()          //plotting no of pixels vs brightness
{     
      Color c1(0,0,0);
      Color c2(255,255,255);
      int max=histogram[0];
      for(int i=0;i<histogram.size();i++)             //finding the maximum number of pixels of certain brightness
      {
            if(max<histogram[i])
            {
                  max=histogram[i];
            }
      }
      Image ans(256,max+1);                           //creating an image of height max and width 256
      for(int i=0;i<max+1;i++)
      {
            for(int j=0;j<256;j++)
            {
                  Pixel *p=new Pixel(i,j,c2);                     //making every pixel white
                  ans.set_p(*p,i,j);
            }
      }
      for(int i=0;i<256;i++)
      {
            Pixel *p3=new Pixel(max-histogram[i],i,c1);                        //for each brightness plotting number of pixels by making pixel black
            ans.set_p(*p3,max-histogram[i],i);
            for(int k=max-histogram[i];k<=max;k++)                        //and drawing a line below that point by making all pixels black
            {
                  Pixel *p1=new Pixel(k,i,c1);
                  ans.set_p(*p1,k,i);
            }
      }
      return ans;                                                 //returning histogram image
}     
