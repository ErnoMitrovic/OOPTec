#include "cMyGame.h"

int MyGame::turn(Board & b, int &cP, int & d){
    std::cout << "CurrentPos: " << cP << "\nDice: " << d << '\n';
    const int MIN = 1, MAX = 30;
    if(cP + d >= MAX)
        return MAX;
    Tile * cT = &b.getTile(cP + d - 1);
    switch (cT->getType())
    {
    case 'S':
        if(cP + d + penalty <= MIN)
            return MIN;
        return cP + d + penalty;
    case 'L':
        if(cP + d + reward >= MAX)
            return MAX;
        return cP + d + reward;
    default:
        return cP + d;
    }
}

void MyGame::turnResults(int & cT, int & cP, Player & p, int & d){
    std::cout << cT << ' ' << p.getNum() << ' ' << cP << ' '
    << d << ' ' << board->getTile(cP + d - 1).getType() 
    << ' ' << p.getCurrentTile()->getNum() << '\n';
}

MyGame::MyGame() : reward(3), penalty(-3), maxTurns(25){
    dice = new Dice();
    board = new Board();
    player1 = new Player("Amy", 1);
    player2 = new Player("Aylin", 2);
}

MyGame & MyGame::instanceGame()
{
    static MyGame instance = MyGame();
    return instance;
}

void MyGame::start(){
    board -> displayBoard();
    char election;
    int diceValue = 0, currentTurn = 1, newTile = 0, currentPos = 0;
    bool win = false;
    std::cout << "- Press C to continue or E to end the game -\n- The display is in the format...\n";
    std::cout << "Turn Player Tile Dice_Number Tile_Type Final_Square\n";
    player1 -> move(board ->getTile(0));
    player2 -> move(board -> getTile(0));
    do{
        std::cin >> election;
        if(election != 'C' && election != 'E') std::cout << "- Invalid input, try again -\n";
        else{
            diceValue = dice ->roll();
            if(currentTurn % 2 == 1){
                currentPos = player1->getCurrentTile()->getNum();
                newTile = turn(*board, currentPos,diceValue);
                player1 -> move(board->getTile(newTile - 1));
                turnResults(currentTurn, currentPos, *player1, diceValue);
                if(player1 -> getCurrentTile()->getNum() == 30){
                    win = true;
                    std::cout << "-- GAME OVER --\nPlayer 1 is the winner!!!\n";
                }
            } else{
                currentPos = player2->getCurrentTile()->getNum();
                newTile = turn(*board, currentPos,diceValue);
                player2 -> move(board->getTile(newTile - 1));
                turnResults(currentTurn, currentPos, *player2, diceValue);
                if(player2 -> getCurrentTile()->getNum() == 30){
                    win = true;
                    std::cout << "-- GAME OVER --\nPlayer 2 is the winner!!!\n";
                }
            }

            currentTurn++;
        }
    } while(election != 'E' && !win && currentPos != maxTurns);
    if(election == 'E')
        std::cout << "Thanks for playing!!!\n";
}