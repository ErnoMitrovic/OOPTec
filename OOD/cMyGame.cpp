#include "cMyGame.h"

/**
 * @brief Construct a new My Game:: My Game object, is private to produce the singleton pattern
 * 
 */
MyGame::MyGame() : reward(3), penalty(-3), maxTurns(25){
    dice = new Dice();
    board = new Board();
    player1 = new Player("Jorge", 1);
    player2 = new Player("Sergio", 2);
}

/**
 * @brief Instantiates a unique MyGame object
 * 
 * @return MyGame& the game object
 */
MyGame & MyGame::instanceGame()
{
    static MyGame instance = MyGame();
    return instance;
}

/**
 * @brief Computes the information for the current turn
 * 
 * @param b board
 * @param cP current position
 * @param d dice value
 * @return int the value of the new position 
 */
int MyGame::turn(Board & b, int &cP, int & d){
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

/**
 * @brief Gives the results of the current turn
 * 
 * @param cT Current turn
 * @param cP Current position
 * @param p player
 * @param d dice value
 */
void MyGame::turnResults(int & cT, int & cP, Player & p, int & d){
    std::cout << cT << ' ' << p.getNum() << ' ' << cP << ' '
    << d << ' ' << board->getTile(cP + d < 30? cP + d - 1 : 29).getType() 
    << ' ' << p.getCurrentTile()->getNum() << '\n';
}

/**
 * @brief Executes the code.
 * 
 */
void MyGame::start(){
    std::cout <<  board ->toString();
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
                std::cout << "Turn player 1: " << newTile << '\n';
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
    } while(election != 'E' && !win && currentPos <= maxTurns);
    if(election == 'E')
        std::cout << "Thanks for playing!!!\n";
}