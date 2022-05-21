#include <iostream>
#include <cstdlib>

class Fraction{
  int num, den;
  int mcd(int, int);
  public:
    Fraction(void);
    Fraction(int, int);
    Fraction* add (Fraction*);
    Fraction* mult (Fraction*);
    void printFrac(void);
    int getNum(void);
    int getDen(void);
};