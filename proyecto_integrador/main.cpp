#include "cCatalog.h"

using namespace std;

int main(){
  Catalog* catalog = new Catalog("./proyecto_integrador/Data.csv");
  cout << catalog -> toString();
  catalog -> menu();
  
  return 0;
}

