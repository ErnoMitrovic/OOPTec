#include "cPlayer.h"

Player::Player(std::string n, int num) : name(n), number(num){}

Player::Player(std::string name) : Player(name, 1){}

Player::Player() : Player("DEFAULT", 1) {}

void Player::setTile(Tile & tile){
  *currentTile = tile;
}