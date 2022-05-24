#include "cTile.h"
class Player
{
private:
    std::string name;
    int number;
    Tile * currentTile;
public:
    Player();
    Player(std::string);
    Player(std::string, int);
    void setTile(Tile &);
    ~Player();
    int getNum(void);
};

