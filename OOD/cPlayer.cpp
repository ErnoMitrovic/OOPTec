#include "cPlayer.h"

/**
 * @brief Construct a new Player:: Player object
 * 
 * @param n name of the player
 * @param num number of the player
 */
Player::Player(std::string n, int num) : name(n), number(num){
  currentTile = new Tile();
}

/**
 * @brief Construct a new Player:: Player object
 * 
 * @param name player's name
 */
Player::Player(std::string name) : Player(name, 1){}

/**
 * @brief Construct a new Player:: Player object with name DEFAULT and number 1
 * 
 */
Player::Player() : Player("DEFAULT", 1) {}
void Player::move(Tile & tile){
  *currentTile = tile;
}

/**
 * @brief Destroy the Player:: Player object
 * 
 */
Player::~Player(){
  delete currentTile, &name, &number;
}

/**
 * @brief Gets the player's number
 * 
 * @return int number
 */
int Player::getNum(){
  return number;
}

/**
 * @brief Gets the current Tile's pointer in which the player stands
 * @see Tile.h
 * 
 * @return Tile* current Tile
 */
Tile * Player::getCurrentTile(){
  return currentTile;
}