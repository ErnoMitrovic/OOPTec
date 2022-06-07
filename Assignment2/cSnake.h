#include "cTile.h"

class Snake : public Tile
{
private:
    int penalty;
public:
    Snake();
    Snake(int);
    Snake(int _num, int _penalty);
    ~Snake();
    void setPenalty(int);
    std::string toString(void) override;
};