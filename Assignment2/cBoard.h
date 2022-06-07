#include <random>
#include <ctime>
#include <iostream>
#include <algorithm>
#include "cLadder.h"
#include "cSnake.h"
#include <vector>
class Board
{
private:
    std::vector<Tile*> matrixBoard;
    int * randomize(const int N, const int MIN, const int MAX);
public:
    Board(void);
    Board(const int & nTiles, const int & nSnakes, const int & nLadder, const int & penalty, const int & reward);
    ~Board();
    std::string toString(void);
    Tile & getTile(int);
};