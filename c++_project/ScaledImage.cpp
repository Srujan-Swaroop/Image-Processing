#include "ScaledImage.h"
#include "CompositeImage.h"
#include <cmath>
#include <iostream>
#include <algorithm>
                                      //ScaledImage implementation
ScaledImage::ScaledImage()  {}        //Default Constructor

ScaledImage::~ScaledImage() {}        //Destructor

ScaledImage::ScaledImage(int wt, int ht): Image(wt, ht), i1(wt, ht), i2(wt, ht), i3(wt, ht), i4(wt, ht) {}  //Parametrized Constructor

void ScaledImage::createPI(Image im){     //Final Image
  int wt = im.get_w();
  int ht = im.get_h();
  Pixel **pix = im.get_pix();
  Pixel **p1;
  Pixel **p2;
  Pixel **p3;
  Pixel **p4; 

  pi = new Pixel *[ht];                     //Array allocation for four pixels
  for(int i = 0; i < ht; i++){
    pi[i] = new Pixel[wt];
  }  
  p1 = new Pixel *[ht];
  for(int i = 0; i < ht; i++){
    p1[i] = new Pixel[wt];
  }
  p2 = new Pixel *[ht];
  for(int i = 0; i < ht; i++){
    p2[i] = new Pixel[wt];
  }
  p3 = new Pixel *[ht];
  for(int i = 0; i < ht; i++){
    p3[i] = new Pixel[wt];
  }
  p4 = new Pixel *[ht];
  for(int i = 0; i < ht; i++){
    p4[i] = new Pixel[wt];
  }    

  i1.set_pix(p1);
  i2.set_pix(p2);
  i3.set_pix(p3);
  i4.set_pix(p4);

  for(int i = 0; i < ht; i++)                     //Making every pixel in the four images white
  {
    for(int j = 0; j < wt; j++)
    {
      pi[i][j].set_p(255, 255, 255);
    }
  }
  for(int i = 0; i < ht; i++)
  {
    for(int j = 0; j < wt; j++)
    {
      p1[i][j].set_p(255, 255, 255);
    }
  }
  for(int i = 0; i < ht; i++)
  {
    for(int j = 0; j < wt; j++)
    {
      p2[i][j].set_p(255, 255, 255);
    }
  }
  for(int i = 0; i < ht; i++)
  {
    for(int j = 0; j < wt; j++)
    {
      p3[i][j].set_p(255, 255, 255);
    }
  }
  for(int i = 0; i < ht; i++)
  {
    for(int j = 0; j < wt; j++)
    {
      p4[i][j].set_p(255, 255, 255);
    }
  }
  if(ht%2 == 1)
  {
    ht = ht - 1;
  }
  if(wt%2 == 1)
  {
    wt = wt - 1;
  }
  /*for(int i = 0; i < ht; i+=2){                           //Modifying the image1
    for(int j = 0; j < wt; j+=2){
      int red = (pix[i][j].get_c().get_r() + pix[i+1][j+1].get_c().get_r() + pix[i+1][j].get_c().get_r() + pix[i][j+1].get_c().get_r())/4;
      int green = (pix[i][j].get_c().get_g() + pix[i+1][j+1].get_c().get_g() + pix[i+1][j].get_c().get_g() + pix[i][j+1].get_c().get_g())/4;
      int blue = (pix[i][j].get_c().get_b() + pix[i+1][j+1].get_c().get_b() + pix[i+1][j].get_c().get_b() + pix[i][j+1].get_c().get_b())/4;
      Color c(red, green, blue);
      p1[i/2][j/2].set_color(c);//pix[i][j].get_c());
    }
  }
  for(int i = 0; i < ht; i+=2){                           //Modifying the image2
    for(int j = 0; j < wt; j+=2){
      int red = (pix[i][j].get_c().get_r() + pix[i+1][j+1].get_c().get_r() + pix[i+1][j].get_c().get_r() + pix[i][j+1].get_c().get_r())/4;
      int green = (pix[i][j].get_c().get_g() + pix[i+1][j+1].get_c().get_g() + pix[i+1][j].get_c().get_g() + pix[i][j+1].get_c().get_g())/4;
      int blue = (pix[i][j].get_c().get_b() + pix[i+1][j+1].get_c().get_b() + pix[i+1][j].get_c().get_b() + pix[i][j+1].get_c().get_b())/4;
      Color c(red, green, blue);
      //pi[i/2][j/2].set_color(c);
      p2[i/2][wt - j/2 - 1].set_color(c);//pix[i][j].get_c());
    }
  }
  for(int i = 0; i < ht; i+=2){                           //Modifying the image3
    for(int j = 0; j < wt; j+=2){
      int red = (pix[i][j].get_c().get_r() + pix[i+1][j+1].get_c().get_r() + pix[i+1][j].get_c().get_r() + pix[i][j+1].get_c().get_r())/4;
      int green = (pix[i][j].get_c().get_g() + pix[i+1][j+1].get_c().get_g() + pix[i+1][j].get_c().get_g() + pix[i][j+1].get_c().get_g())/4;
      int blue = (pix[i][j].get_c().get_b() + pix[i+1][j+1].get_c().get_b() + pix[i+1][j].get_c().get_b() + pix[i][j+1].get_c().get_b())/4;
      Color c(red, green, blue);
      //pi[i/2][j/2].set_color(c);
      p3[ht - i/2 - 1][wt - j/2 - 1].set_color(c);//pix[i][j].get_c());
    }
  }
  for(int i = 0; i < ht; i+=2){                           //Modifying the image4
    for(int j = 0; j < wt; j+=2){
      int red = (pix[i][j].get_c().get_r() + pix[i+1][j+1].get_c().get_r() + pix[i+1][j].get_c().get_r() + pix[i][j+1].get_c().get_r())/4;
      int green = (pix[i][j].get_c().get_g() + pix[i+1][j+1].get_c().get_g() + pix[i+1][j].get_c().get_g() + pix[i][j+1].get_c().get_g())/4;
      int blue = (pix[i][j].get_c().get_b() + pix[i+1][j+1].get_c().get_b() + pix[i+1][j].get_c().get_b() + pix[i][j+1].get_c().get_b())/4;
      Color c(red, green, blue);
      //pi[i/2][j/2].set_color(c);
      p4[ht - i/2 - 1][j/2].set_color(c);//pix[i][j].get_c());
    }
  }
  CompositeImage c1(i1, i2, 0.5);                        //Compositing the images.
  CompositeImage c2(i3, i4, 0.5);
  CompositeImage c3(c1, c2, 0.5);
  pi = c3.get_pix();*/
  
  for(int i = 0; i < ht; i+=2){                           //Modifying the image1
    for(int j = 0; j < wt; j+=2){
      int red = (pix[i][j].get_c().get_r() + pix[i+1][j+1].get_c().get_r() + pix[i+1][j].get_c().get_r() + pix[i][j+1].get_c().get_r())/4;
      int green = (pix[i][j].get_c().get_g() + pix[i+1][j+1].get_c().get_g() + pix[i+1][j].get_c().get_g() + pix[i][j+1].get_c().get_g())/4;
      int blue = (pix[i][j].get_c().get_b() + pix[i+1][j+1].get_c().get_b() + pix[i+1][j].get_c().get_b() + pix[i][j+1].get_c().get_b())/4;
      Color c(red, green, blue);
      //pi[i/2][j/2].set_color(c);
      pi[i/2][j/2].set_color(c);//pix[i][j].get_c());
    }
  }
  for(int i = 0; i < ht; i+=2){                           //Modifying the image2
    for(int j = 0; j < wt; j+=2){
      int red = (pix[i][j].get_c().get_r() + pix[i+1][j+1].get_c().get_r() + pix[i+1][j].get_c().get_r() + pix[i][j+1].get_c().get_r())/4;
      int green = (pix[i][j].get_c().get_g() + pix[i+1][j+1].get_c().get_g() + pix[i+1][j].get_c().get_g() + pix[i][j+1].get_c().get_g())/4;
      int blue = (pix[i][j].get_c().get_b() + pix[i+1][j+1].get_c().get_b() + pix[i+1][j].get_c().get_b() + pix[i][j+1].get_c().get_b())/4;
      Color c(red, green, blue);
      //pi[i/2][j/2].set_color(c);
      pi[i/2][wt - j/2 - 1].set_color(c);//pix[i][j].get_c());
    }
  }
  for(int i = 0; i < ht; i+=2){                           //Modifying the image3
    for(int j = 0; j < wt; j+=2){
      int red = (pix[i][j].get_c().get_r() + pix[i+1][j+1].get_c().get_r() + pix[i+1][j].get_c().get_r() + pix[i][j+1].get_c().get_r())/4;
      int green = (pix[i][j].get_c().get_g() + pix[i+1][j+1].get_c().get_g() + pix[i+1][j].get_c().get_g() + pix[i][j+1].get_c().get_g())/4;
      int blue = (pix[i][j].get_c().get_b() + pix[i+1][j+1].get_c().get_b() + pix[i+1][j].get_c().get_b() + pix[i][j+1].get_c().get_b())/4;
      Color c(red, green, blue);
      //pi[i/2][j/2].set_color(c);
      pi[ht - i/2 - 1][wt - j/2 - 1].set_color(c);//pix[i][j].get_c());
    }
  }
  for(int i = 0; i < ht; i+=2){                           //Modifying the image4
    for(int j = 0; j < wt; j+=2){
      int red = (pix[i][j].get_c().get_r() + pix[i+1][j+1].get_c().get_r() + pix[i+1][j].get_c().get_r() + pix[i][j+1].get_c().get_r())/4;
      int green = (pix[i][j].get_c().get_g() + pix[i+1][j+1].get_c().get_g() + pix[i+1][j].get_c().get_g() + pix[i][j+1].get_c().get_g())/4;
      int blue = (pix[i][j].get_c().get_b() + pix[i+1][j+1].get_c().get_b() + pix[i+1][j].get_c().get_b() + pix[i][j+1].get_c().get_b())/4;
      Color c(red, green, blue);
      //pi[i/2][j/2].set_color(c);
      pi[ht - i/2 - 1][j/2].set_color(c);//pix[i][j].get_c());
    }
  }

  for (int i = 0; i < ht; i++){                           //Stenciling the final Image.
    for(int j = 0; j < wt; j++){ 
      if(i < min(floor(wt/4), floor(ht/4)) || j < min(floor(wt/4), floor(ht/4)) || i > 3*min(floor(wt/4), floor(ht/4)) || j > 3*min(floor(wt/4), floor(ht/4))){//||(i < b && j < b)||(i < b && j < a)){
        pi[i][j].set_p(255, 255, 255);
      }
    }
  }
}

std :: ostream& operator<<(std :: ostream &os, ScaledImage &sim)      //Ostream << operator overloading for ScaledImage
{
  for(int i = 0; i < sim._h; i++)
  {
    for(int j = 0; j < sim._w; j++)
    {
      os << sim.pi[i][j] << " ";
    }
    os <<'\n';
  }
  return os;
}
