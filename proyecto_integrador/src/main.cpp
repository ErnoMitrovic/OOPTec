#include "cCatalog.h"

using namespace std;

int main(){
  Catalog* catalog = new Catalog("./Data.csv");
  cout << catalog -> toString();
  catalog -> menu();
  
  return 0;
}

