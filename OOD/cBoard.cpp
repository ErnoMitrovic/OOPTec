#include "cBoard.h"

Board::Board(){
    matrixBoard = new char*[30];
    for(unsigned int i = 0; i < 30; i++){
        matrixBoard[i] = new char[30];
        for(unsigned j = 0; j < 30; j++){
            matrixBoard[i][j] = 'N';
        }
    }
    std::srand(std::time(NULL));
    int * boxesPos;
    boxesPos = new int [12];
    for(unsigned short i = 0; i < 12; i++){
        boxesPos[i] = std::rand() % 30;
    }
    for(unsigned short i = 0; i < 6; i+=2){
        matrixBoard[boxesPos[i]][boxesPos[i+1]] = 'S';
    }
    for(unsigned short i = 6; i < 12; i+=2){
        matrixBoard[boxesPos[i]][boxesPos[i+1]] = 'L';
    }
    delete boxesPos;
}

Board::~Board(){
    delete [] matrixBoard;
}

void Board::displayBoard(){
    for(unsigned int i = 0; i < 30; i++){
        for(unsigned int j = 0; j < 30; j++){
            std::cout << matrixBoard[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

char Board::getBox(int * currentPosition){
    return matrixBoard[*currentPosition][*(currentPosition + 1)];
}