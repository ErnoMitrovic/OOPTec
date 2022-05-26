#include "cPlayer.h"

Player::Player(std::string n, int num) : name(n), number(num){
  currentTile = new Tile();
}

Player::Player(std::string name) : Player(name, 1){}

Player::Player() : Player("DEFAULT", 1) {}
void Player::move(Tile & tile){
  *currentTile = tile;
}

Player::~Player(){}
int Player::getNum(){
  return number;
}

Tile * Player::getCurrentTile(){
  return currentTile;
}