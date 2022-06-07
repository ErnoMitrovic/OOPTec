#include "cPolar.h"

/*
  private:
    float r, ang;
  public:
    Polar();
    Polar(float r, float ang);
    std::string toString(void);
    Polar operator + (const Polar &, const Polar &);
*/

Polar::Polar(double r, double ang){
  this -> r = r;
  this -> ang = ang;
}

Polar::Polar() : Polar(1,0){}

std::string Polar::toString(){
  std::string info = "";
  info += "RADIUS: " + std::to_string(r) + 
    "\nANGLE: " + std::to_string(ang) + "\n";
  return info;
}

Polar Polar::operator+(const Polar & p2){
  double x, y;
  x = r * std::cos(ang) + p2.r * std::cos(p2.ang);
  y = r * std::sin(ang) + p2.r * std::sin(p2.ang);
  return Polar(std::sqrt(x*x + y*y), std::atan(y/x));
}