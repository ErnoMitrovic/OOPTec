#include "cTile.h"

/**
* Initializes a Tile with its number
*/
Tile::Tile(int n): type('N'), num(n){}

/**
* Default constructor
*/
Tile::Tile() : Tile(0) {}


/**
* Default destructor
*/

Tile::~Tile(){}

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
  out += "\nNum: " + std::to_string(num) + "\n";
  return out;
}

/**
 * @brief Setter of type
 * 
 * @param t type of tile
 */
void Tile::setType(char t){
  type = t;
}