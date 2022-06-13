#include "cMovie.h"

/**
* Namespace para los casos de debug
*/
namespace testCases{

}

#include <vector>
#include <iostream>

int main(){
  std::vector <Video*> vds;
  vds.push_back(new Movie());
  std::cout << vds.at(0)->toString();
  return 0;
}