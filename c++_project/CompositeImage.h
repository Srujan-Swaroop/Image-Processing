#ifndef CompositeImage_H
#define CompositeImage_H
#include "Image.h"
#include "Color.h"
#include "Pixel.h"

class CompositeImage : public Image
{
  public:
    CompositeImage();
    CompositeImage(Image a, Image b, float alpha);
    ~CompositeImage();
    CompositeImage(const CompositeImage& other);
};

#endif
