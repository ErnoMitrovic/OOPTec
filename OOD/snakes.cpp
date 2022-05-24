#include "cMyGame.h"

int main(){
    /* Dice * dice = new Dice();
    std::cout << "Value: " << dice -> roll(); */
    Tile * t = new Tile('S', 2);
    std::cout << (t -> toString());
}