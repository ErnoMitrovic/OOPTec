#include "cMyGame.h"

int main(){
    std::srand((unsigned) std::time(0));
    Tile t;
    int sum = 0;
    // MyGame * myGame = &MyGame::instanceGame();
    // myGame->start();
    for(int i = 0; i < 3; i++){
        sum = i + 1;
        t = Tile(sum);
        std::cout << t.toString();
    }
}