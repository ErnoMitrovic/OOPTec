#include "cMyGame.h"

MyGame::MyGame()
{
    char elect;
    do
    {
        std::cout << "Default values (Y/N) ";
        std::cin >> elect;
        elect = std::toupper(elect);
    } while (elect != 'Y' && elect != 'N');
    if (elect == 'Y')
    {
        dice = new Dice();
        board = new Board();
        penalty = -3;
        reward = 3;
        maxTurns = 20;
        players.push_back(new Player("Erno", 1));
        players.push_back(new Player("Regi", 2));
    }
    else
    {
        dice = new Dice();
        int nT, nS, nL, nP;
        std::vector<Player *> pls;
        std::cout << "- STARTING SETUP -\n- Number of tiles: ";
        std::cin >> nT;
        do
        {
            std::cout << "- Number of snakes: ";
            std::cin >> nS;
            std::cout << "- Number of ladders: ";
            std::cin >> nL;
            if (nS + nL > nT)
            {
                std::cout << "* Invalid input, exceeded number of tiles *\n";
            }
        } while (nS + nL > nT);
        std::cout << "- Penalty: ";
        std::cin >> penalty;
        std::cout << "- Reward: ";
        std::cin >> reward;
        board = new Board(nT, nS, nL, penalty, reward);
        std::cout << "- Number of players: ";
        std::cin >> nP;
        for (unsigned short i = 0; i < nP; i++)
        {
            std::string name;
            int num;
            std::cout << "-- Name: ";
            std::cin >> name;
            std::cout << "-- Num: ";
            std::cin >> num;
            pls.push_back(new Player(name, num));
        }
        players = pls;
        std::cout << "- Number of turns: ";
        std::cin >> maxTurns;
    }
}

/**
 * @brief Computes the information for the current turn
 *
 * @param b board
 * @param cP current position
 * @param d dice value
 * @return int the value of the new position
 */
int MyGame::turn(Board &b, int &cP, int &d)
{
    const int MIN = 1, MAX = 30;
    if (cP + d >= MAX)
        return MAX;
    Tile *cT = &b.getTile(cP + d - 1);
    switch (cT->getType())
    {
    case 'S':
        if (cP + d + penalty <= MIN)
            return MIN;
        return cP + d + penalty;
    case 'L':
        if (cP + d + reward >= MAX)
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
void MyGame::turnResults(int &cT, int &cP, Player &p, int &d)
{
    std::cout << cT << ' ' << p.getNum() << ' ' << cP << ' '
              << d << ' ' << board->getTile(cP + d < 30 ? cP + d - 1 : 29).getType()
              << ' ' << p.getCurrentTile()->getNum() << '\n';
}

/**
 * @brief Returns an unique instance of MyGame object
 *
 * @return MyGame&
 */
MyGame &MyGame::instanceGame()
{
    static MyGame instance;
    return instance;
}

/**
 * @brief Executes the code manual mode.
 *
 */
void MyGame::startM()
{
    char election;
    do
    {
        std::cout << "Display board (Y/N): ";
        std::cin >> election;
        election = std::toupper(election);
        switch (election)
        {
        case 'Y':
            std::cout << board->toString();
            break;
        case 'N':
            std::cout << '\n';
            break;
        default:
            std::cout << "Invalid output...\n";
            break;
        }
    } while (election != 'Y' && election != 'N');
    int diceValue = 0, currentTurn = 1, newTile = 0, currentPos = 0;
    bool win = false;
    std::cout << "- Press C to continue or E to end the game -\n- The display is in the format...\n";
    std::cout << "Turn Player Tile Dice_Number Tile_Type Final_Square\n";
    for (unsigned short i = 0; i < players.size(); i++)
    {
        players[i]->move(board->getTile(0));
    }
    int totalPlayers = players.size(), currentPlayer = 0;
    do
    {
        std::cin >> election;
        election = std::toupper(election);
        if (election != 'C' && election != 'E')
            std::cout << "- Invalid input, try again -\n";
        else if (election == 'E' || currentTurn > maxTurns)
            std::cout << "Thanks for playing!!!\n";
        else
        {
            diceValue = dice->roll();
            currentPos = players[currentPlayer]->getCurrentTile()->getNum();
            newTile = turn(*board, currentPos, diceValue);
            players[currentPlayer]->move(board->getTile(newTile - 1));
            turnResults(currentTurn, currentPos, *players[currentPlayer], diceValue);
            if (players[currentPlayer]->getCurrentTile()->getNum() == 30)
            {
                win = true;
                std::cout << "-- GAME OVER --\nPlayer " << players[currentPlayer]->getNum() << " is the winner!!!\n";
            }

            currentTurn++;
            if (currentPlayer + 1 == totalPlayers)
                currentPlayer = 0;
            else
                currentPlayer++;
        }
    } while (election != 'E' && !win && currentTurn <= maxTurns);
}

void MyGame::startA()
{
    char election;
    do
    {
        std::cout << "Display board (Y/N): ";
        std::cin >> election;
        election = std::toupper(election);
        switch (election)
        {
        case 'Y':
            std::cout << board->toString();
            break;
        case 'N':
            std::cout << '\n';
            break;
        default:
            std::cout << "Invalid output...\n";
            break;
        }
    } while (election != 'Y' && election != 'N');
    int diceValue = 0, currentTurn = 1, newTile = 0, currentPos = 0;
    bool win = false;
    for (unsigned short i = 0; i < players.size(); i++)
    {
        players[i]->move(board->getTile(0));
    }
    int totalPlayers = players.size(), currentPlayer = 0;
    do
    {
        diceValue = dice->roll();
        currentPos = players[currentPlayer]->getCurrentTile()->getNum();
        newTile = turn(*board, currentPos, diceValue);
        players[currentPlayer]->move(board->getTile(newTile - 1));
        turnResults(currentTurn, currentPos, *players[currentPlayer], diceValue);
        if (players[currentPlayer]->getCurrentTile()->getNum() == 30)
        {
            win = true;
            std::cout << "-- GAME OVER --\nPlayer " << players[currentPlayer]->getNum() << " is the winner!!!\n";
        }

        currentTurn++;
        if (currentPlayer + 1 == totalPlayers)
            currentPlayer = 0;
        else
            currentPlayer++;
    } while (election != 'E' && !win && currentTurn <= maxTurns);
}

void MyGame::start(){
    char election;
    do{
        std::cout << "Automatic play or Manual (A/M) ";
        std::cin >> election;
        election = std::toupper(election);
        switch(election){
            case 'A':
                startA();
                break;
            case 'M':
                startM();
                break;
            default:
                std::cout << "Invalid input\n";
                break;
        }
    } while(election != 'A' && election != 'M');
}