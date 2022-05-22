#include "cDice.h"

Dice::Dice(){
    std::srand(std::time(NULL));
}

Dice::~Dice(){
    delete &value;
}

int Dice::turnDice(){
    value = std::rand() % 6 + 1;
    return value;
}