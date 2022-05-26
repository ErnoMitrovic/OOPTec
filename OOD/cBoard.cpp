#include "cBoard.h"

int * Board::randomize(const int N, const int MIN = 0, const int MAX = 10){
  if(MAX < N) return NULL; // MAX must be greater or equal than N
  int * nums = new int[N];
  for(unsigned short i = 0; i < N; i++){
    bool used;
    int n;
    do{
      n = (std::rand() % (MAX - MIN + 1)) + MIN;;
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

Board::Board(){
  matrixBoard = new Tile[30];
  int * nums = new int[6];

  for (unsigned short i = 0; i < 30; i++){
    matrixBoard[i] = Tile(i + 1);
  }
  nums = randomize(6, 1, 30);
  for(unsigned short i = 0; i < 6; i++){
    matrixBoard[nums[i]] = i < 3 ? Tile('S', nums[i]) : Tile('L', nums[i]);
  }
}

Board::~Board(){
    delete [] matrixBoard;
}

void Board::displayBoard(){
  for(unsigned short i = 0; i < 30; i++){ 
    std::cout << matrixBoard[i].getType() << ' ';
    if((i + 1 )% 6   == 0)
      std::cout << '\n';
  }
}

Tile & Board::getTile(int currentPosition){
    return matrixBoard[currentPosition];
}