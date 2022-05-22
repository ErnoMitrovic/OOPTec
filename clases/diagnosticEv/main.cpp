#include "cMatFrac.h"

void debug(){
  MatFrac * m1 = new MatFrac(4), *m2 = new MatFrac(4);
  m1 -> printFracs();
  std::cout << '\n';
  m2 -> printFracs();
  m1 -> sumMats(m2, "./debug.txt");
}

int main(){
  /* MatFrac * m1 = new MatFrac("./mat1.txt"),
  * m2 = new MatFrac("./mat2.txt");
  m1 -> printFracs();
  std::cout << " + \n";
  m2->printFracs();
  std::cout << " = \n";
  std::cout << "--- See file generated ---\n";
  m1->sumMats(m2, "./addition.txt"); */
  debug();
}