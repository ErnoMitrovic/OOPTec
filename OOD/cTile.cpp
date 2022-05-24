#include "cTile.h"

/**
* Setter for type
*/
void Tile::setType(char type){
  this -> type = type;
}

/**
* Default constructor
*/
Tile::Tile(){
  setType('N');
  num = 0;
}

/**
* Initializes a Tile with its number
*/
Tile::Tile(int n): num(n){
  setType('N');
}

/**
* Default destructor
*/

Tile::~Tile(){
  delete &num;
  delete &type;
}

int Tile::getNum(){
  return num;
}

char Tile::getType(){
  return type;
}

std::string Tile::toString(){
  std::string out = "";
  out += "Type: ";
  out += type;
  out += "\nNum: " + std::to_string(num) + '\n';
  return out;
}