#include "cTile.h"

class Snake : public Tile
{
private:
    int reward;
public:
    Snake();
    Snake(int);
    Snake(int _num, int _reward);
    ~Snake();
    void setReward(int);
    std::string toString(void) override;
};