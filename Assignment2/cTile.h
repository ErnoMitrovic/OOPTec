#pragma once
#include <string>
class Tile{
  char type;
  int num;
  public:
    Tile();
    Tile(int);
    ~Tile();
    int getNum(void);
    char getType(void);
    void setType(char);
    virtual std::string toString(void);
};