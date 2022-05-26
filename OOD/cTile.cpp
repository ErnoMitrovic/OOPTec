#include "cTile.h"

/**
* Setter for type
*/
void Tile::setType(char type){
  this -> type = type;
}

Tile::Tile(char t, int n) : num(n){
  setType(t);
}

/**
* Initializes a Tile with its number
*/
Tile::Tile(int n): Tile('N', n){}


/**
* Default constructor
*/
Tile::Tile() : Tile('N', 0){}


/**
* Default destructor
*/

Tile::~Tile(){}

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