#include "cMatFrac.h"

int main(){
  std::srand(time(NULL));
  MatFrac * m1 = new MatFrac("./mat1.txt"),
  * m2 = new MatFrac("./mat2.txt");
  m1 -> printFracs();
  std::cout << " + \n";
  m2->printFracs();
  std::cout << " = \n";
  std::cout << "--- See file generated ---\n";
  std::cout << "- Filepath: \"./addition.txt\"\n";
  m1->sumMats(m2, "./addition.txt"); 
}