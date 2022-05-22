#include "cMyGame.h"

int main(){
    Dice * dice = new Dice();
    std::cout << "Value: " << dice -> roll();
}