#include <random>
#include <ctime>
#include <iostream>
#include <algorithm>
#include "cTile.h"
class Board
{
private:
    Tile * matrixBoard;
    int * randomize(const int N, const int MIN, const int MAX);
public:
    Board(void);
    ~Board();
    std::string toString(void);
    Tile & getTile(int);
};