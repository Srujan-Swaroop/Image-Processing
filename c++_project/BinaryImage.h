#ifndef BINARYIMAGE_H
#define BINARYIMAGE_H
#include "Color.h"
#include "Pixel.h"
#include "Image.h"

using namespace std;
class BinaryImage: public Image{
public:
  BinaryImage();
  BinaryImage(Image& img,int th);
  BinaryImage(Image& img,int th,Color fg_col,Color bg_col);
  BinaryImage(const BinaryImage &other);
  ~BinaryImage();
};
#endif
