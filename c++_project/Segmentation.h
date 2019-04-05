#ifndef SEGMENTATION_H
#define SEGMENTATION_H
#include "Image.h"
#include "Histogram.h"
#include "Reflection_x.h"
#include "CompositeImage.h"

class Segmentation: public Image
{
  public:
      Segmentation();
      ~Segmentation();
      Segmentation(Image i,float alpha);
};

#endif
