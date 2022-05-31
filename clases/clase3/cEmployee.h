#pragma once

#include "cPerson.h"
class Employee : public Person{
  float salary;
  public:
    Employee();
    Employee(std::string);
    Employee(std::string, float);
    std::string toString() override;
};