#include <iostream>

class Fraction{
  int num, den;
  int mcd(int, int);
  public:
    Fraction();
    Fraction(int, int);
    Fraction* add (Fraction*);
    Fraction* mult (Fraction*);
    void printFrac(void);
};