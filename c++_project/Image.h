#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include "Color.h"
#include "Pixel.h"

class Image
{
protected:
  int _w,_h;
  Pixel **_p;
public:
  Image();
  Image(int w, int h);
  Image(const Image &i);
  ~Image();

  Pixel get_p(int x, int y);
  Pixel& get_pr(int x, int y);
  int get_w();
  int get_h();
  Pixel** get_pix();

  void set_p(Pixel p, int x, int y);
  void set_size(int w,int h);
  void set_pix(Pixel ** p);

  friend ostream & operator << (ostream &out, Image &i);
	friend istream & operator >> (istream &is, Image &i);
  Image& operator=(Image const &other);
};

#endif
