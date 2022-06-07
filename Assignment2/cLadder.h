#include "cTile.h"

class Ladder : public Tile
{
private:
    int reward;
public:
    Ladder();
    Ladder(int);
    Ladder(int _num, int _reward);
    ~Ladder();
    void setReward(int);
    std::string toString(void) override;
};