#include "Image.h"
#include <iostream>

using namespace std;

Image::Image(){};

Image::Image(int w,int h)
{
  _w = w;
  _h = h;
  _p = new Pixel*[h];
  for(int i = 0; i < h; i++)
  {
    _p[i] = new Pixel[w];
  }
}

Image::Image(const Image &i): _w(i._w), _h(i._h){
  _p = new Pixel*[_h];
  for(int j = 0; j < _h; j++)
  {
    _p[j] = new Pixel[_w];
  }
  for(int j=0;j<_h;j++){
    for(int k=0;k<_w;k++){
      _p[j][k] = i._p[j][k];
    }
  }
}

Image:: ~Image(){
  for(int i=0;i<_h;i++){
    delete[] _p[i];
  }
  delete[] _p;
  _w = 0;
  _h = 0;
}

Pixel Image::get_p(int x, int y)
{
  return _p[x][y];
}

Pixel& Image::get_pr(int x, int y)
{
  return _p[x][y];
}

int Image::get_w()
{
  return _w;
}

int Image::get_h()
{
  return _h;
}

Pixel** Image::get_pix(){
  return _p;
}

void Image::set_p(Pixel p, int x, int y)
{
  _p[x][y] = p;
}

void Image::set_size(int w,int h){
  _w = w;
  _h = h;
  _p = new Pixel*[_h];
  for(int j = 0; j < _h; j++)
  {
    _p[j] = new Pixel[_w];
  }
}

void Image::set_pix(Pixel ** p){
  _p = p;
}

ostream & operator << (ostream &out, Image &i)
{
  for(int j=0;j<i._h;j++)
  {
    for(int k=0;k<i._w;k++)
    {
      out<<i._p[j][k]<<" ";
    }
    out<<endl;
  }
  return out;
}

istream& operator >> (istream& is, Image &img){
  for(int i=0;i<img.get_h();i++){
    for(int j=0;j<img.get_w();j++){
      int x,y,z;
      is >> x >> y >> z;
      img._p[i][j].set_p(x,y,z);
    }
  }
  return is;
}

Image& Image::operator=(Image const &other)
{
  _h = other._h;
  _w = other._w;
  _p = new Pixel*[_h];
  for(int i = 0; i < _h; i++)
  {
    _p[i] = new Pixel[_w];
  }
  for(int i=0;i<_h;i++)
  {
    for(int j=0;j<_w;j++)
    {
      _p[i][j] = other._p[i][j];
    }
  }
  return *(this);
}
