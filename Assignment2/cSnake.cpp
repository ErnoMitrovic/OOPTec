#include "cSnake.h"

/*
    int penalty;
public:
    Snake();
    Snake(int);
    ~Snake();
    void setPenalty(int);
    std::string toString(void) override;
*/

/**
 * @brief Construct a new Snakeobject
 * 
 * @param _num number of the tile
 * @param _penalty penalty value
 */
Snake::Snake(int _num, int _penalty) : Tile(_num), penalty(_penalty){
    setType('S');
}

/**
 * @brief Construct a new Snake object with penalty set to 3
 * 
 * @param _num number of tile
 */
Snake::Snake(int _num) : Snake(_num, -3) {}

/**
 * @brief Construct a new Snake object
 * 
 */
Snake::Snake() : Snake(1, -3) {}

/**
 * @brief Destroy the Snake object
 * 
 */
Snake::~Snake() {}

/**
 * @brief Setter of the penalty
 * 
 * @param _penalty 
 */
void Snake::setPenalty(int _penalty){
    penalty = _penalty;
}

/**
 * @brief Returns the infomation of the Snake Tile
 * 
 * @return std::string information
 */
std::string Snake::toString(){
    std::string info = Tile::toString();
    info += "Reward: " + std::to_string(penalty) + "\n";
    return info;
}