#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

class Point{
  float x, y, z;

  public: 
    Point();
    Point(float, float, float);
    string toString();
    float distance(Point *);
};