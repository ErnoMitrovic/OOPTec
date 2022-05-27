#include "cEmployee.h"

class User : public Employee{
  std::string at;
  public:
    User();
    User(std::string);
    User(std::string name, std::string at);
    std::string toString() override;
};