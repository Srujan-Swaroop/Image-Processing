#ifndef PIXEL_H
#define PIXEL_H
#include"Color.h"

#include <iostream>
using namespace std;

class Pixel
{
  private:
    int _x;
    int _y;
    Color _col;

  public:
    Pixel();
    Pixel(int x, int y, Color col);
    ~Pixel();
    Pixel(Pixel &pix);

    int get_x();
    int get_y();
    Color get_c();
    int get_brightness();

    void set_p(float r, float g, float b);
    void set_color(Color c);
    friend ostream & operator << (ostream &op, Pixel &pix);
    Pixel& operator=(Pixel const &other);

    friend Pixel& operator+(Pixel pixel1, Pixel pixel2);
    friend Pixel& operator*(float f, Pixel pixel2);
};
#endif
