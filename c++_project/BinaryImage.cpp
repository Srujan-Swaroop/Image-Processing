#include "Color.h"
#include "Pixel.h"
#include "Image.h"
#include "BinaryImage.h"

using namespace std;

BinaryImage:: BinaryImage(): Image(){

}

BinaryImage:: BinaryImage(Image &img,int th): Image(img.get_w(),img.get_h()){
  int w = img.get_w();
  int h = img.get_h();
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      Color tempCol;
      if(img.get_p(i,j).get_brightness()<th){
        tempCol.set_r(0);
        tempCol.set_g(0);
        tempCol.set_b(0);
      }
      else{
        tempCol.set_r(255);
        tempCol.set_g(255);
        tempCol.set_b(255);
      }
      _p[i][j].set_color(tempCol);
    }
  }
}

BinaryImage:: BinaryImage(Image& img,int th,Color fg_col,Color bg_col):
Image(img.get_w(),img.get_h()){
  int w = img.get_w();
  int h = img.get_h();
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(img.get_p(i,j).get_brightness()<th){
        _p[i][j].set_color(bg_col);
      }
      else{
        _p[i][j].set_color(fg_col);
      }
    }
  }
}

BinaryImage:: BinaryImage(const BinaryImage &other): Image(other){

}

BinaryImage:: ~BinaryImage(){

}
