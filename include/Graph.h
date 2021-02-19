#ifndef Graph_H
#define Graph_H

#include<vector>

#include "BicyclePath.h"

using namespace std;

class Graph {
private:
  int pointsCount;
  vector< Point > touristicPoints;
  vector< BicyclePath > bicyclePaths;
  vector< BicyclePath > minSpanningTree;
  vector< int > touristicPointsPaths;
  int mstCost;
  int mstAttractiveness;

public:
  Graph(vector< Point > touristicPoints);
  void addBicyclePath(Point firstPoint, Point secondPoint, int cost);
  void calculateMinSpanningTree();
  vector< BicyclePath > getMinSpanningTree();
  vector< int > getTouristicPointsPaths();
  int getMstCost();
  int getMstAttractiveness();
};

#endif
