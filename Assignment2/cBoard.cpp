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
 * @brief Construct a new Board:: Board object
 * 
 */
Board::Board(){
  matrixBoard = new Tile[30];
  int * nums = new int[6];
  for (int i = 0; i < 30; i++){
    matrixBoard[i] = Tile(i + 1);
  }
  nums = randomize(6, 29);
  for(unsigned short i = 0; i < 6; i++){
    matrixBoard[nums[i]] = i < 3 ? Tile('S', nums[i] + 1) : Tile('L', nums[i] + 1);
  }
}

/**
 * @brief Destroy the Board:: Board object
 * 
 */
Board::~Board(){
    delete [] matrixBoard;
}

/**
 * @brief Gives information of the board
 * 
 * @return std::string string representation of the board
 */
std::string Board::toString(){
  std::string info = "";
  for(int i = 0; i < 30; i++){ 
    info += matrixBoard[i].getType();
    info += ' ';
    if((i + 1)% 6   == 0)
      info += '\n';
  }
  return info;
}

/**
 * @brief Gets the current tile
 * 
 * @param currentPosition current position of the player (must be in index format)
 * @return Tile& the tile reference according to the position
 */
Tile & Board::getTile(int currentPosition){
    return matrixBoard[currentPosition];
}