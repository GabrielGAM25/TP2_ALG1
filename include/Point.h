#ifndef Point_H
#define Point_H

class Point {
private:
  int id;
  int touristicValue;

public:
  Point();
  Point(int id, int touristicValue);
  void setTouristicValue(int touristicValue);
  int getTouristicValue();
  int getId();
};

#endif
