#ifndef BicyclePath_H
#define BicyclePath_H

#include "Point.h"

using namespace std;

class BicyclePath {
private:
  Point firstPoint;
  Point secondPoint;
  int cost;

public:
  BicyclePath(Point firstPoint, Point secondPoint, int cost);
  int getAttractiviteness();
  Point getFirstPoint();
  Point getSecondPoint();
  int getCost();
};

#endif
