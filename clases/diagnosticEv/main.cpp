#include "cFraction.h"

int main(){
  Fraction* f1 = new Fraction(), *f2 = new Fraction(6,8);
  f1 -> printFrac();
  f2 -> printFrac();
  Fraction * sum = f2 -> add(f2);
  sum -> printFrac();
  return 0;
}