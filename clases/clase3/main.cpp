#include "cEmployee.h"
#include "cUser.h"
#include <iostream>

int main(){
  Person * p = new Person("Erno");
  Employee * e = new Employee("Ernesto", 15000.f);
  User * u = new User("Ernesto", "ernoMitrovic");
  std::cout << p -> toString();
  std::cout << e -> toString();
  std::cout << u -> toString();
  
  return 0;
}