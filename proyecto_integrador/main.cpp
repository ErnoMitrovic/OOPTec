// #include "cCatalog.h"
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

/**
* Namespace para los casos de debug
*/
namespace testCases{

}

int main(){

  // Catalog* catalog = new Catalog("./Data.csv");
  // catalog -> menu();
  vector <string> v;
  vector<string>::iterator it;
  v.push_back("Jorge");
  v.push_back("Erno");
  v.push_back("Raul");
  v.push_back("Sebas");
  // Esto lo va a encontrar
  it = find(v.begin(),v.end(),"Raul");
  (*it) = "XD";
  for(it = v.begin(); it < v.end(); it++){
    cout << *it << "\n";
  }
  
  return 0;
}

