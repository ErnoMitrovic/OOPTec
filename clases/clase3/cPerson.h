#pragma once
#include <string>

class Person{
  private:
    std::string name;
  public:
    Person();
    Person(std::string);
    virtual std::string toString(void);
};