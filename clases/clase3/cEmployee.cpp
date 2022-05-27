#include "cEmployee.h"
/*
    Employee();
    Employee(std::string);
    Employee(std::string, float);
    std::string toString() override;
*/

Employee::Employee(std::string n, float s) : Person(n), salary(s){}

Employee::Employee(std::string n) : Person(n), salary(0){}

Employee::Employee() : Person(), salary(0){}

std::string Employee::toString(){
  std::string info = Person::toString();
  info += "Salary: $" +  std::to_string(salary) + "\n";
  return info;
}