#ifndef CONNECTEDCOMPONENT_H
#define CONNECTEDCOMPONENT_H

#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>
#include "Color.h"
#include "Pixel.h"
#include "Image.h"

using namespace std;

class ConnectedComponent: public Image{
private:
  Color *black;// for all unconnected components
  vector<Color> colors;// for assigning diff colors to diff connected components
  vector<int> labels;// array of all different labels in img
  vector<vector<int> > equi_labels;// adjacency list
  vector<vector<int> > matrix;// matrix in which matrix[i][j] holds the label for img[i][j]
  vector<int> vis;// for dfs
public:
  ConnectedComponent();
  ConnectedComponent(Image& img);
  ~ConnectedComponent();

  void dfs();
  void dfsVisit(int s);
};
#endif
