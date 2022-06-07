#include "cMyGame.h"

int main(){
    std::srand((unsigned) std::time(0));
    MyGame * myGame = &MyGame::instanceGame();
    myGame -> start();
}