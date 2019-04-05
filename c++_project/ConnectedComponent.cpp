#include "ConnectedComponent.h"
#include<iostream>
#include <cmath>
#include<vector>
#include<set>
#include<algorithm>
#include "Color.h"
#include "Pixel.h"
#include "Image.h"

using namespace std;

void ConnectedComponent:: dfsVisit(int s){
  vis[s]=1;
  for(int i=0;i<equi_labels[s].size();i++){
    if(vis[equi_labels[s][i]]==0){
      labels[equi_labels[s][i]]=labels[s];
      dfsVisit(equi_labels[s][i]);
    }
  }
}

void ConnectedComponent:: dfs(){
  for(int i=1;i<equi_labels.size();i++){
    if(vis[i]==0){
      dfsVisit(i);
    }
  }
}

ConnectedComponent:: ConnectedComponent(){

}

ConnectedComponent:: ~ConnectedComponent(){

}

ConnectedComponent:: ConnectedComponent(Image& img){
  black = new Color(0,0,0);
  _w = img.get_w();
  _h = img.get_h();
  _p = new Pixel*[_h];
  for(int i = 0; i < _h; i++)
  {
    _p[i] = new Pixel[_w];
  }
  matrix.resize(_h);
  for(int i=0;i<_h;i++){
    matrix[i].resize(_w);
  }
  for(int i=0;i<_h;i++){// initial labelling start
    for(int j=0;j<_w;j++){
      if(img.get_p(i,j).get_c()==*black){
        matrix[i][j]=1;
      }
      else{
        matrix[i][j]=0;
      }
    }
  }// initial labelling end
  labels.push_back(0);
  vector<int> temp;
  equi_labels.push_back(temp);
  vis.push_back(0);

  for(int i=0;i<_h;i++){// first pass start
    for(int j=0;j<_w;j++){
      if(matrix[i][j]==1){
        set<int> tempSet;
        if(i!=0){
          for(int x=-1;x<2;x++){
            if(j+x>=0 and j+x<_w and matrix[i-1][j+x]!=0){
              tempSet.insert(matrix[i-1][j+x]);
            }
          }
        }
        if(j!=0 and matrix[i][j-1]!=0){
          tempSet.insert(matrix[i][j-1]);
        }
        if(tempSet.size()==0){
          matrix[i][j] = labels.size();
          labels.push_back(matrix[i][j]);
          vector<int> temp;
          equi_labels.push_back(temp);
          vis.push_back(0);
        }
        else if(tempSet.size()==1){
          matrix[i][j] = *(tempSet.begin());
        }
        else{
          int minLabel = *(tempSet.begin());
          matrix[i][j] = minLabel;
          set<int>:: iterator itr = tempSet.begin();
          while(itr!=tempSet.end()){
            itr++;
            equi_labels[minLabel].push_back(*itr);
          }
        }
      }
    }
  }// first pass end

  dfs();// second pass for resolving equivalent labels

  int r=0,g=0,b=0;// generating colors start
  colors.push_back(*black);
  for(int i=1;i<100;i++){
    if(i%3==0){
      r = (r+80)%256;
    }
    else if(i%3==1){
      g = (g+160)%256;
    }
    else{
      b = (b+120)%256;
    }
    Color temp(r,g,b);
    colors.push_back(temp);
  }// generating colors end

  for(int i=0;i<_h;i++){// assigning colors to labels start
    for(int j=0;j<_w;j++){
      Pixel * tempPix = new Pixel(i,j,colors[labels[matrix[i][j]]%100]);
      set_p(*tempPix,i,j);
      //cout << labels[matrix[i][j]] << endl;
    }
  }// assigning colors to labels end
}
