#include "../include/Point.h"

Point::Point() {
  touristicValue = 0;
  this->id = -1;
}

Point::Point(int id, int touristicValue) {
  this->touristicValue = touristicValue;
  this->id = id;
}

void Point::setTouristicValue(int touristicValue) {
  this->touristicValue = touristicValue;
}

int Point::getTouristicValue() {
  return touristicValue;
}

int Point::getId() {
  return id;
}
