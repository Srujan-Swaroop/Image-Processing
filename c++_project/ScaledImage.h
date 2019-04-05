#ifndef SCALEDIMAGE_H
#define SCALEDIMAGE_H
#include "Image.h"
#include <iostream>

class ScaledImage: public Image{			//ScaledImage class Interface
public:
  ScaledImage();							//ScaledImage default constructor
  ~ScaledImage();							//ScaledImage destructor
  ScaledImage(int wt, int ht);				//ScaledImage parametrized constructor
  void createPI(Image im);					//A method to create the final image
  friend ostream& operator<<(std :: ostream &os, ScaledImage &sim);			//friend function to output the image
  
private:
  Image i1, i2, i3, i4;						//Four different images 
  Pixel **pi;								//Final pixel array
};
#endif