
#include "cBoard.h"
#include "cDice.h"
#include "cPlayer.h"
#include <iostream>

class MyGame{
  int reward, penalty, maxTurns;
  Dice * dice;
  std::vector <Player *> players;
  Board * board;
  int turn(Board &, int & currentPos, int & dice);
  void turnResults(int & currentTurn, int & currentPos, Player & player, int & diceVal);
  MyGame();
  public:
    void startM(void);
    void startA(void);
    static MyGame & instanceGame(void);
    MyGame(MyGame const &) = delete;
    void operator=(MyGame const &) = delete;
    void start(void);
};