#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Image.h"
#include "Color.h"
#include "Pixel.h"

using namespace std;

class Histogram
{
  private:
    vector<int> histogram;
    vector<int> threshold;
    vector< vector<int> > brightness;

  public:
    Histogram();
    ~Histogram();
    Histogram(Image i);
    int  modify(vector <int> v);
    Image picture();
    vector<int> getThreshold();
    vector< vector<int> > getBrightness();
    int getMedianThreshold();
};

#endif
