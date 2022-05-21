#include "cMatFrac.h"

int main(){
  // MatFrac * m1 = new MatFrac("./test.txt");
  // m1 -> printFracs();
  std::ifstream s;
  s.open("test.txt");
  if(!s){
    std::cerr << "File couldn't be opened\n";
    exit(1);
  }
}