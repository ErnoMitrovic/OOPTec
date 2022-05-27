#include "cUser.h"
/*
    User();
    User(std::string);
    User(std::string name, std::string at);
    std::string toString() override;
*/

User::User(std::string n, std::string a) : Employee(n), at(a){}

User::User(std::string n) : Employee(n), at("@" + n){}

User::User() : Employee(), at("@def"){}

#include <iostream>
std::string User::toString(){
  std::string info = Person::toString();
  info += "At: " + at + "\n";
  return info;
}