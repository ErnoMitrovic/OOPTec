#include "cDice.h"

/**
 * Default constructor of Dice
*/
Dice::Dice(){}

/**
 * @brief Destroy the Dice object
 * Deletes the memory allocated in value
 */
Dice::~Dice(){
    delete &value;
}

/**
 * @brief Rolls the dice in a range of values from 1 to 6
 * 
 * @return int the random value
 */
int Dice::roll(){
    value = std::rand() % 6 + 1;
    return value;
}