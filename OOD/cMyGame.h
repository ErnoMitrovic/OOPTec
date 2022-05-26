
#include "cBoard.h"
#include "cDice.h"
#include "cPlayer.h"
#include <iostream>

class MyGame{
  // The class implements singleton
  int const reward, penalty, maxTurns;
  Dice * dice;
  Player * player1, * player2;
  Board * board;
  MyGame();
  int turn(Board &, int & currentPos, int & dice);
  void turnResults(int & currentTurn, int & currentPos, Player & player, int & diceVal);
  public:
    static MyGame & instanceGame();
    void start();
    MyGame(MyGame const &) = delete;
    void operator=(MyGame const &) = delete;
};