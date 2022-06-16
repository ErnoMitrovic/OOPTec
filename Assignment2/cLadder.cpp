#include "cLadder.h"

/*
    int penalty;
public:
    Ladder();
    Ladder(int);
    ~Ladder();
    void setPenalty(int);
    std::string toString(void) override;
*/

/**
 * @brief Construct a new Ladder object
 * 
 * @param _num number of the tile
 * @param _reward reward value
 */
Ladder::Ladder(int _num, int _reward) : Tile(_num), reward(_reward){
    setType('L');
}

/**
 * @brief Construct a new Ladder object with reward set to 3
 * 
 * @param _num number of tile
 */
Ladder::Ladder(int _num) : Ladder(_num, 3) {}

/**
 * @brief Construct a new Ladder object
 * 
 */
Ladder::Ladder() : Ladder(1, 3) {}

/**
 * @brief Destroy the Ladder object
 * 
 */
Ladder::~Ladder() {}

/**
 * @brief Setter of the reward
 * 
 * @param _penalty 
 */
void Ladder::setReward(int _reward){
    reward = _reward;
}

/**
 * @brief Returns the infomation of the Ladder Tile
 * 
 * @return std::string information
 */
std::string Ladder::toString(){
    std::string info = Tile::toString();
    info += "Reward: " + std::to_string(reward) + "\n";
    return info;
}