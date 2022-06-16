#include "cCatalog.h"

using namespace std;

/**
* Namespace para los casos de debug
*/
namespace testCases{
#include <iostream>
  void debug(){
    vector<Episode*> ep;
    ep.push_back(new Episode());
    ep.push_back(new Episode());
    ep.push_back(new Episode());
    ep[0]->setRating(2.f);
    ep[1]->setRating(4.f);
    ep[2]->setRating(1.3f);
    Series c(ep, "DEF");
    cout << c.avgRating() << endl;
  }
}


int main(){
  Catalog* catalog = new Catalog("./proyecto_integrador/Data.csv");
  catalog -> menu();
  
  return 0;
}

