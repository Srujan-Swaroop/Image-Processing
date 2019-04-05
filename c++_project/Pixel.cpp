#include "Pixel.h"

#include <cmath>
#include <iostream>

using namespace std;

Pixel::Pixel(){};

Pixel::Pixel(int x, int y, Color col) : _x(x), _y(y), _col(col){};

Pixel::Pixel(Pixel &pix) : _x(pix._x), _y(pix._y), _col(pix._col){};

Pixel::~Pixel(){}

int Pixel::get_x()
{
  return _x;
}

int Pixel::get_y()
{
  return _y;
}

Color Pixel::get_c()
{
  return _col;
}

int Pixel::get_brightness()
{
  return (_col.get_r()+_col.get_g()+_col.get_b())/3;
}

void Pixel::set_p(float r, float g, float b)
{
  _col.set_r(r);
  _col.set_g(g);
  _col.set_b(b);
}

void Pixel::set_color(Color c){
  _col = c;
}

ostream &operator<<(ostream &op, Pixel &pix)
{
  op << pix._col;
  return op;
}

Pixel & Pixel::operator =(Pixel const &other)
{
  _x = other._x;
  _y = other._y;
  _col = other._col;
  return (*(this));
}

Pixel & operator +(Pixel pixel1, Pixel pixel2)
{
  if (pixel1.get_x() == pixel2.get_x() && pixel1.get_y() == pixel2.get_y())
  {
    int r = pixel1.get_c().get_r() + pixel2.get_c().get_r();
    int g = pixel1.get_c().get_g() + pixel2.get_c().get_g();
    int b = pixel1.get_c().get_b() + pixel2.get_c().get_b();
    Color col(r, g, b);//doubt do we need new?
    Pixel &p = *(new Pixel(pixel1.get_x(), pixel1.get_y(), col));
    return p;
  }

}

Pixel & operator *(float f, Pixel pixel2)
{
  int r = f * pixel2.get_c().get_r();
  int g = f * pixel2.get_c().get_g();
  int b = f * pixel2.get_c().get_b();
  if (r > 255)
    r = 255;
  if (g > 255)
    g = 255;
  if (b > 255)
    b = 255;
  Color col(r, g, b);
  Pixel &p = *(new Pixel(pixel2.get_x(), pixel2.get_y(), col));
  return p;
}
