
#include "cBoard.h"
#include "cDice.h"
#include "cPlayer.h"
#include <iostream>

class MyGame{
  // The class implements singleton
  int const reward, penalty, maxTurns;
  Dice * dice;
  std::vector <Player *> players;
  Board * board;
  MyGame();
  MyGame(const int nT, const int nS, const int nL, const int p, const int r, const std::vector<Player*> & pls, const int t);
  int turn(Board &, int & currentPos, int & dice);
  void turnResults(int & currentTurn, int & currentPos, Player & player, int & diceVal);
  static MyGame setup(void);
  public:
    static MyGame & instanceGame(void);
    void start(void);
    MyGame(MyGame const &) = delete;
    void operator=(MyGame const &) = delete;
};