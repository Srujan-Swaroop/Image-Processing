#include "Segmentation.h"
#include "Reflection_y.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include<fstream>

using namespace std;

Segmentation::Segmentation(){};

Segmentation::~Segmentation(){};

Segmentation::Segmentation(Image im,float alpha) : Image(im.get_w(),im.get_h())
{

  Histogram hist(im);
  vector<int> threshold = hist.getThreshold();
  int len=threshold.size();
  vector< vector<int> > brightness=hist.getBrightness();
  int h = im.get_h();
  int w = im.get_w();
    if(len!=0)
    {
      int colors[6][3];
      for(int i = 0; i < 3; i++)
      {
        for(int j = 0; j < 3; j++)
        {
          colors[i][j] = 0;
        }
      }
      for(int i = 0; i < 3; i++)
      {
        colors[i][i] = 255;
      }

      for(int i = 3; i < 6; i++)
      {
        for(int j = 0;j < 3; j++)
        {
          colors[i][j] = 255;
        }
      }

      for(int i = 0;i < 3; i++)
      {
        colors[3+i][2-i] = 0;
      }

      for(int i = 0;i < h; i++)
      {
        for(int j = 0; j < w; j++)
        {
          for(int k = 0; k < len; k++)
          {
            if(brightness[i][j] < threshold[k])
            {
              if(k < 6)
              {
                Color c(colors[k][0], colors[k][1], colors[k][2]);
                Pixel p(i, j, c);
                (*this).set_p(p, i, j);
              }
              else
              {
                Color c(0, 0, 0);
                Pixel p(i, j, c);
                (*this).set_p(p, i, j);
              }
              break;
            }
          }
          if(brightness[i][j] > threshold[len-1])
          {
            if(len < 6)
            {
              Color c(colors[len][0], colors[len][1], colors[len][2]);
              Pixel p(i, j, c);
              (*this).set_p(p, i, j);
            }
            else
            {
              Color c(0, 0, 0);
              Pixel p(i, j, c);
              (*this).set_p(p, i, j);
            }
          }
        }
      }
  }
  else
  {
    Reflection_y r1(im);
    for(int i = 0; i < _h; i++)
    {
      for(int j = 0; j < _w; j++)
      {
        _p[i][j] = r1.get_p(i, j);
      }
    }
  }
  CompositeImage c(im, (*this), alpha);
  for(int i = 0; i < _h; i++)
  {
    for(int j = 0; j < _w; j++)
    {
      _p[i][j] = c.get_p(i, j);
    }
  }
}
