#include "cBoard.h"

/**
 * @brief Randomize numbers without repetition
 * 
 * @param N number of values
 * @param MAX maximum value
 * @param MIN minimum value, default is 0
 * @return int* pointer to the different values
 */
int * Board::randomize(const int N, const int MAX, const int MIN = 0){
  if(MAX < N) return NULL; // MAX must be greater or equal than N
  int * nums = new int[N];
  for(unsigned short i = 0; i < N; i++){
    bool used;
    int n;
    do{
      n = (std::rand() % (MAX - MIN + 1)) + MIN;
      used = true;
      for(unsigned short j = 0; j < i; j++){
        if(n == nums[j]){
          used = false;
          break;
        }
      }
    } while (!used);
    nums[i] = n;
  }
  return nums;
}
/**
 * @brief Construct a new Board object
 * 
 * @param nTiles number of tiles
 * @param nSnakes number of Snakes
 * @param nLadder number of Ladder
 */
Board::Board(const int & nTiles, const int & nSnakes, const int & nLadder, const int & penalty, const int & reward){
  int * nums = new int[nSnakes + nLadder];
  for (unsigned short i = 0; i < nTiles; i++){
    matrixBoard.push_back(new Tile(i+1));
  }
  nums = randomize(nSnakes + nLadder, nTiles-1);
  for(unsigned short i = 0; i < nSnakes + nLadder; i++){
    if (i < nSnakes)
      matrixBoard[nums[i]] = new Snake(nums[i] + 1);
    else 
      matrixBoard[nums[i]] = new Ladder(nums[i] + 1);
  }
}

/**
 * @brief Construct a new Board:: Board object
 * 
 */
Board::Board() : Board(30, 3, 3, -3, 3){}

/**
 * @brief Destroy the Board:: Board object
 * 
 */
Board::~Board(){}

/**
 * @brief Gives information of the board
 * 
 * @return std::string string representation of the board
 */
std::string Board::toString(){
  std::string info = "";
  for(int i = 0; i < matrixBoard.size(); i++){ 
    info += matrixBoard[i]->getType();
    info += ' ';
    if((i + 1)% 6   == 0)
      info += '\n';
  }
  info += '\n';
  return info;
}

/**
 * @brief Gets the current tile
 * 
 * @param currentPosition current position of the player (must be in index format)
 * @return Tile& the tile reference according to the position
 */
Tile & Board::getTile(int currentPosition){
    return *matrixBoard[currentPosition];
}