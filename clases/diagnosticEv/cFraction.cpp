#include "cFraction.h"

/**
* Obtains the maximum common denominator
*/
int Fraction::mcd(int num1, int num2){
  if(num2 == 0)
    return num1;
  else 
    return mcd(num2, num1%num2);
}

/**
* Instantiate a 0/1 fraction
*/
Fraction::Fraction() : num(0), den(1){}

/**
* Instantiate a simplified fraction
*/
Fraction::Fraction(int n, int d) {
  int *p, temp;
  temp = mcd(n, d);
  p = &temp;
  den = d / *p;
  num = n / *p;
}

/**
* Implemets addition of fractions
*/
Fraction* Fraction::add (Fraction* f2){
  int numerator, denominator;
  numerator= num * f2 ->den + den * f2 -> num;
  denominator = den * f2 -> den;
  return new Fraction(numerator, denominator);
}

/**
* Implemets multiplication of fractions
*/
Fraction* Fraction::mult (Fraction* f2){
  int numerator = num * f2 -> num, 
  denominator = den * f2 -> den;
  return new Fraction(numerator, denominator);
}

/**
* Implemets printing of fractions
*/
void Fraction::printFrac(void){
  std::cout << num << '/' << den;
}

int Fraction::getNum(){
  return num;
}

int Fraction::getDen(){
  return den;
}