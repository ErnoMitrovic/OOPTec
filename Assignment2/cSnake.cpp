#include "cSnake.h"

/*
    int reward;
public:
    Snake();
    Snake(int);
    ~Snake();
    void setReward(int);
    std::string toString(void) override;
*/

/**
 * @brief Construct a new Snakeobject
 * 
 * @param _num number of the tile
 * @param _reward reward value
 */
Snake::Snake(int _num, int _reward) : Tile(_num), reward(_reward){
    setType('S');
}

/**
 * @brief Construct a new Snake object with reward set to 3
 * 
 * @param _num number of tile
 */
Snake::Snake(int _num) : Snake(_num, 3) {}

/**
 * @brief Construct a new Snake object
 * 
 */
Snake::Snake() : Snake(1, 3) {}

/**
 * @brief Destroy the Snake object
 * 
 */
Snake::~Snake() {}

/**
 * @brief Setter of the reward
 * 
 * @param _reward 
 */
void Snake::setReward(int _reward){
    reward = _reward;
}

/**
 * @brief Returns the infomation of the Snake Tile
 * 
 * @return std::string information
 */
std::string Snake::toString(){
    std::string info = Tile::toString();
    info += "Reward: " + std::to_string(reward) + "\n";
    return info;
}