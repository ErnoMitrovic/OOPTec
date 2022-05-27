#include "cPerson.h"
/*
    Person();
    Person(std::string);
    std::string toString(void);
    std::string getName();
*/

Person::Person(std::string n) : name(n){}

Person::Person() : Person("DEF") {}

std::string Person::toString(){
  std::string info = "";
  info += "Name: " + name + "\n";
  return info;
}

std::string Person::getName(){
  return name;
}