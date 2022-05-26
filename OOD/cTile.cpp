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

Tile::~Tile(){
  delete &type, &num;
}

/**
 * @brief Gets the number corresponding to the tile
 * 
 * @return int the number
 */
int Tile::getNum(){
  return num;
}

/**
 * @brief Gets the type allocated in this tile
 * 
 * @return char 'S' for snake, 'L' for ladder and 'N' for normal
 */
char Tile::getType(){
  return type;
}

/**
 * @brief String representation of the Tile object
 * 
 * @return std::string the string representation
 */
std::string Tile::toString(){
  std::string out = "";
  out += "Type: ";
  out += type;
  out += "\nNum: " + std::to_string(num) + '\n';
  return out;
}