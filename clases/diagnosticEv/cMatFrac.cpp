#include "cMatFrac.h"

MatFrac::~MatFrac(){
  delete [] * matriz;
}

std::string * MatFrac::split(std::string str, std::string delimiter = " "){
  std::string * splitStr;
  int start = 0, end = str.find(delimiter), count = 0;
  while(end != -1){
    start = end + delimiter.size();
    end = str.find(delimiter, start);
    count++;
  }
  count++;

  splitStr = new std::string[count];
  start = 0; end = str.find(delimiter); count = 0;
  while(end != -1){
    splitStr[count] = str.substr(start, end - start);
    start = end + delimiter.size();
    end = str.find(delimiter, start);
    count++;
  }
  splitStr[count] = str.substr(start, end - start);
  return splitStr;
}

void MatFrac::debug(){
  
}

void MatFrac::str2Frac(std::string * fracs){
  std::stringstream ss;
  std::string * rowFracs, * temp;
  int num, den;
  matriz = new Fraction*[size];
  for(int i = 0; i < size; i++){
    matriz[i] = new Fraction[size];
    rowFracs = split(fracs[i]);
    for(int j = 0; j < size; j++){
      temp = split(rowFracs[j], "/");
      ss << temp[0];
      ss >> num;
      ss.clear();
      ss << temp[1];
      ss >> den;
      ss.clear();
      matriz[i][j] = Fraction(num, den);
    }
  }
}

MatFrac::MatFrac(int size){
  this -> size = size;
  matriz = new Fraction*[size];
  for(int i = 0; i < size; i++){
    matriz[i] = new Fraction[size];
    for(int j = 0; j < size; j++){
      int num, den;
      num= std::rand() % 20;
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
  size = 0;
  while (std::getline(matDoc, rawFrac, '\n'))
    size++;
  rawFracs = new std::string[size];
  matDoc.clear();
  matDoc.seekg(0);
  for(int i = 0; i < size; i++){
    std::getline(matDoc, rawFrac);
    rawFracs[i] = rawFrac;
  }
  matDoc.close();
  str2Frac(rawFracs);
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