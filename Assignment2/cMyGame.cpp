#include "cMyGame.h"

MyGame::MyGame(const int nT, const int nS, const int nL, const int p, const int r, const std::vector<Player*> & pls, const int t)
: penalty(p), reward(r), maxTurns(t){
    dice = new Dice();
    board = new Board(nT, nS, nL, p, r);
    players = pls;
}

/**
 * @brief Construct a new My Game:: My Game object, is private to produce the singleton pattern
 * 
 */
MyGame::MyGame() : reward(3), penalty(-3), maxTurns(20){
    dice = new Dice();
    board = new Board();
    players.push_back(new Player("Benjamin", 1));
    players.push_back(new Player("Sergio", 2));
}

/**
 * @brief Instantiates a unique MyGame object
 * 
 * @return MyGame& the game object
 */
MyGame & MyGame::instanceGame()
{
    static MyGame instance;
    char select;
    do{
        std::cout << "Default values? (Y/N) ";
        std::cin >> select;
        select = std::toupper(select);
        switch(select){
            case 'Y':
                return  instance;
            case 'N':
                return setup();
            default:
                std::cout << "Invalid input\n";
                break;
        }
    } while(select != 'Y' || select != 'N');
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

MyGame MyGame::setup(){
    int nT, nS, nL, p, r, nP, t;
    std::vector<Player*> pls;
    std::cout << "- STARTING SETUP -\n- Number of tiles: ";
    std::cin >> nT;
    do{
        std::cout << "- Number of snakes: ";
        std::cin >> nS;
        std::cout << "- Number of ladders: ";
        std::cin >> nL;
        if(nS + nL > nT){
            std::cout << "* Invalid input, exceeded number of tiles *\n";
        }
    } while(nS + nL > nT);
    std::cout << "- Penalty: ";
    std::cin >> p;
    std::cout << "- Reward: ";
    std::cin >> r;
    std::cout << "Number of players: ";
    std::cin >> nP;
    for(unsigned short i = 0; i < nP; i++){
        std::string name;
        int num;
        std::cout << "-- Name: ";
        std::cin >> name;
        std::cout << "-- Num: ";
        std::cin >> num;
        pls.push_back(new Player(name, num));
    }
    std::cout << "- Number of turns: ";
    std::cin >> t;
    return MyGame(nT, nS, nL, p, r, pls, t);
}

/**
 * @brief Executes the code.
 * 
 */
void MyGame::start(){
    char election;
    do{
        std::cout << "Display board (Y/N): ";
        std::cin >> election;
        election = std::toupper(election);
        switch(election){
            case 'Y':
                std::cout <<  board ->toString();
                break;
            case 'N':
                std::cout << '\n';
                break;
            default:
                std::cout << "Invalid output...\n";
                break;
        }
    } while(election != 'Y' && election != 'N');
    int diceValue = 0, currentTurn = 1, newTile = 0, currentPos = 0;
    bool win = false;
    std::cout << "- Press C to continue or E to end the game -\n- The display is in the format...\n";
    std::cout << "Turn Player Tile Dice_Number Tile_Type Final_Square\n";
    players[0] -> move(board ->getTile(0));
    players[1] -> move(board -> getTile(0));
    do{
        std::cin >> election;
        election = std::toupper(election);
        if(election != 'C' && election != 'E') std::cout << "- Invalid input, try again -\n";
        else if(election == 'E' || currentTurn > maxTurns)
            std::cout << "Thanks for playing!!!\n";
        else{
            diceValue = dice ->roll();
            if(currentTurn % 2 == 1){
                currentPos = players[0]->getCurrentTile()->getNum();
                newTile = turn(*board, currentPos,diceValue);
                players[0] -> move(board->getTile(newTile - 1));
                turnResults(currentTurn, currentPos, *players[0], diceValue);
                if(players[0] -> getCurrentTile()->getNum() == 30){
                    win = true;
                    std::cout << "-- GAME OVER --\nPlayer 1 is the winner!!!\n";
                }
            } else{
                currentPos = players[1]->getCurrentTile()->getNum();
                newTile = turn(*board, currentPos,diceValue);
                players[1] -> move(board->getTile(newTile - 1));
                turnResults(currentTurn, currentPos, *players[1], diceValue);
                if(players[1] -> getCurrentTile()->getNum() == 30){
                    win = true;
                    std::cout << "-- GAME OVER --\nPlayer 2 is the winner!!!\n";
                }
            }

            currentTurn++;
        }
    } while(election != 'E' && !win && currentTurn <= maxTurns);
}