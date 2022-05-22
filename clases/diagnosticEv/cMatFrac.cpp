#include "cMatFrac.h"

std::string * MatFrac::split(std::string str, char delimiter){
  std::string * strSplit;
  int i;
  size = i = 0;
  for(auto ch : str){
    if (ch == delimiter)
      size++;
  }
  strSplit = new std::string [size];
  for(auto ch : str){
    std::string temp = "";
    if (ch != delimiter)
      temp += ch;
    else {
      strSplit[i] = temp;
      i++;
    }
  } 
  return strSplit;
}

void MatFrac::str2Frac(std::string * fracs, int size){
  matriz = new Fraction*[size];
  for(int i = 0; i < size; i++){
    matriz[i] = new Fraction[size];
    std::string * rowFracs = split(fracs[i], ' ');
    for(int j = 0; j < size; j++){
      std::string * temp = split(rowFracs[j], '/');
      matriz[i][j] = Fraction(std::stoi(temp[0]), std::stoi(temp[1]));
    }
  }
}

MatFrac::MatFrac(int size){
  this -> size = size;
  srand(time(NULL));
  matriz = new Fraction*[size];
  for(int i = 0; i < size; i++){
    matriz[i] = new Fraction[size];
    for(int j = 0; j < size; j++){
      int num, den;
      num= std::rand() % 20 +1;
      den = std::rand() % 20 + 1;
      matriz[i][j] = Fraction(num, den);
    }
  }
}

MatFrac::MatFrac() : MatFrac(3){}

MatFrac::MatFrac(std::string filepath){
  std::ifstream matDoc;
  std::string * rawFracs, rawFrac;
  matDoc.open(filepath);
  if(!matDoc){
    std::cerr << "File couldn't be opened\n";    
    exit(1);
  }
  int nrows = 0;
  while (std::getline(matDoc, rawFrac))
    nrows++;
  rawFracs = new std::string[nrows];
  for(int i = 0; i < nrows; i++){
    std::getline(matDoc, rawFrac);
    rawFracs[i] = rawFrac;
  }
  matDoc.close();
  str2Frac(rawFracs, nrows);
}

int MatFrac::getSize(){
  return size;
}

void MatFrac::sumMats (MatFrac * m2, const std::string filename){
  if(size == m2 -> getSize()){
    std::ofstream mat(filename);
    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        Fraction * sum = new Fraction();
        sum = matriz[i][j].add(& m2 -> matriz[i][j]);
        mat << sum -> getNum() << '/' << sum -> getDen() << ' ';
      }
      mat << '\n';
    }
    return;
  }
  std::cerr << "Matrices have differente sizes.\n";
  exit(0);
}

void MatFrac::printFracs(){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      matriz[i][j].printFrac();
      std::cout << ' ';
    }
    std::cout << '\n';
  }
}