#include<bits/stdc++.h>
#include "Color.h"
#include "Pixel.h"
#include "Image.h"
#include "CompositeImage.h"
#include "ConnectedComponent.h"
#include "Histogram.h"
#include "Segmentation.h"
#include "ScaledImage.h"
#include "Task5.h"
#include "Reflection_x.h"
#include "Reflection_y.h"
#include "Clipping.h"
#include "Stenciling.h"
#include "Generateforone.h"
#include "BinaryImage.h"

using namespace std;

void input_ppm(ifstream &in,Image &img){
  string s;
  int w,h,maxVal;
  in >> s;
  in >> w >> h;
  img.set_size(w,h);
  in >> maxVal;
  in >> img;
}

void output_ppm(ofstream &out,Image &img){
  string s = "P3";
  out << s << "\n";
  out << img.get_w() << " " << img.get_h() << "\n";
  out << 255 << "\n";
  out << img;
}

Image * input_img = new Image();
Image * noise = new Image();
int w,h;

void generateNoise(int w,int h){
  noise->set_size(w,h);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      int x,y,z;
      x = rand()%256;
      y = rand()%256;
      z = rand()%256;
      Color * tempCol = new Color(x,y,z);
      Pixel * tempPix = new Pixel(i,j,*tempCol);
      (*noise).set_p(*tempPix,i,j);
    }
  }
}

void task1(){
  Generateforone m(w,h);
  Reflection_y refl(*input_img);//image reflection
  Stenciling Stenc(refl,m);//stenciling output
  Clipping clip(*input_img,m);

  CompositeImage comp(clip,Stenc,0.5);
  ofstream out("output_task1_imt2016121.ppm");
  output_ppm(out,comp);
}

void task4(){
  Segmentation seg(*input_img,0.4);
  ofstream out("output_task4_imt2016004.ppm");
  output_ppm(out,seg);
}

void task5(){
  float f=0.2;
  Task5 ans1(w,h);
  ans1.convert1(*input_img);
  Task5 ans2(w,h);
  ans2.convert2(*input_img);
  CompositeImage com(ans2,ans1,f);
  ofstream out("output_task5_imt2016033.ppm");
  output_ppm(out,com);
}

void task6(){
  Histogram histogram(*input_img);
  int th = histogram.getMedianThreshold();
  //cout << th << endl;
  BinaryImage binary(*input_img,th);
  ConnectedComponent output_img(binary);
  ofstream out("output_task6_imt2016102.ppm");
  output_ppm(out,output_img);
}

void task7(){
  ScaledImage sci(input_img->get_w(), input_img->get_h());
  sci.createPI(*input_img);
  ofstream out("output_task7_imt2016060.ppm");
  string s = "P3";
  out << s << "\n";
  out << sci.get_w() << " " << sci.get_h() << "\n";
  out << 255 << "\n";
  out << sci;
  //cout << "task7end\n";
}

void task8(){
  generateNoise(w,h);
  CompositeImage composite_img(*noise,*input_img,0.5);
  Histogram histogram(composite_img);
  int th = histogram.getMedianThreshold();
  //cout << th << endl;
  BinaryImage binary(composite_img,th);
  ConnectedComponent output_img(binary);
  ofstream out("output_task8_imt2016082.ppm");
  output_ppm(out,output_img);
}

int main(int argc,char * argv[]){
  ifstream inputFile(argv[1]);
  input_ppm(inputFile,(*input_img));
  w = input_img->get_w();
  h = input_img->get_h();
  Histogram histo(*input_img);
  BinaryImage binary_img(*input_img,histo.getMedianThreshold());
  ofstream out_binary("Binary.ppm");
  output_ppm(out_binary,binary_img);
  cout << "Our group task ID combination is 4 5 6 7 8 1\n";
  int task_id = 1;
  while(task_id != 0){
    cout << "Enter the task ID: 4/5/6/7/8/1 or 0 to Exit\n";
    cin >> task_id;
    if(task_id==0){
      break;
    }
    if(task_id==4){
      task4();
    }
    else if(task_id==5){
      task5();
    }
    else if(task_id==6){
      task6();
    }
    else if(task_id==7){
      task7();
    }
    else if(task_id==8){
      task8();
    }
    else if(task_id==1){
      task1();
    }
    else{
      cout << "Wrong task ID entered\n";
    }
  }
  return 0;
}
