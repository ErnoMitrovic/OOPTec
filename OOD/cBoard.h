#include <random>
#include <ctime>
#include <iostream>
class Board
{
private:
    char ** matrixBoard;
public:
    Board(void);
    ~Board(void);
    void displayBoard(void);
    char getBox(int *);
};