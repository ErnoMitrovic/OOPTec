#include "cPoint.hpp"

Point::Point(){
  x = y = z = 0;
}

Point::Point(float x0, float y0, float z0) : x(x0), y(y0), z(z0){}

string Point::toString(){
  string txt = "[";
  txt += to_string(x) + ", ";
  txt += to_string(y) + ", ";
  txt += to_string(z) + "]";
  return txt;
}

float Point::distance(Point * p){
  float dx = p->x - x,
  dy = p->y - y,
  dz = p->z - z;
  return sqrt(dx*dx + dy*dy + dz*dz);
}