#include <iostream>
#include "cPolar.h"

#define PI 3.1415926545897932

int main(){
  Polar p1(2, PI/6), p2 (3, PI/8), p3;
  std::cout << p1.toString() << '\n';
  std::cout << p2.toString() << '\n';
  p3 = p1 + p2;
  std::cout << p3.toString() << '\n';
}