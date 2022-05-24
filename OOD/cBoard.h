#include <random>
#include <ctime>
#include <iostream>
#include "cTile.h"
class Board
{
private:
    Tile * matrixBoard;
public:
    Board(void);
    ~Board(void);
    void displayBoard(void);
    Tile getTile(int);
};