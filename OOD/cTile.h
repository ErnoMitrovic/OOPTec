#pragma once
#include <string>
class Tile{
  char type;
  int num;
  public:
    Tile();
    Tile(int);
    Tile(char, int);
    ~Tile();
    int getNum(void);
    char getType(void);
    void setType(char);
    std::string toString(void);
};