#include "cBoard.h"

Board::Board(){
  matrixBoard = new Tile[30];
  int * pos;
  for (unsigned short i = 0; i < 30; i++){
    matrixBoard[i] = Tile(i);
    std::cout << "Im here\n";
  }
  
  for(unsigned short i = 0; i < 6; i++){
    *pos = rand() % 30;
    *(matrixBoard + *pos) = i < 3 ? Tile('S', *pos) : Tile('L', *pos);
  }
  delete pos;
}

Board::~Board(){
    delete [] matrixBoard;
}

void Board::displayBoard(){
  for(unsigned short i = 0; i < 30; i++){ 
    std::cout << matrixBoard[i].getType() << ' ';
    if((i + 1 )% 3 == 0)
      std::cout << '\n';
  }
}

Tile Board::getTile(int currentPosition){
    return matrixBoard[currentPosition];
}