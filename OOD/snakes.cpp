#include "cMyGame.h"

int main(){
    Dice * dice = new Dice();
    int value = dice ->turnDice();
    std::cout << "Value: " << value;
}