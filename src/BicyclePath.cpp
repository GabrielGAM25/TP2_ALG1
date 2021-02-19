#include "../include/BicyclePath.h"

BicyclePath::BicyclePath(Point firstPoint, Point secondPoint, int cost) {
  this->firstPoint = firstPoint;
  this->secondPoint = secondPoint;
  this->cost = cost;
}

int BicyclePath::getAttractiviteness() {
  int firstPointTouristicValue = firstPoint.getTouristicValue();
  int secondPointTouristicValue = secondPoint.getTouristicValue();

  return firstPointTouristicValue + secondPointTouristicValue;
}

Point BicyclePath::getFirstPoint() {
  return firstPoint;
}

Point BicyclePath::getSecondPoint() {
  return secondPoint;
}

int BicyclePath::getCost() {
  return cost;
}
