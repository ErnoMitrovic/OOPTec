#include "cMatFrac.h"

MatFrac::~MatFrac(){
  delete [] * matriz;
}

std::string * MatFrac::split(std::string str, char delimiter){
  std::string * strSplit, temp = "";
  int val, index;
  val = index = 0;
  for(char ch : str){
    if (ch == delimiter)
      val++;
  }
  strSplit = new std::string [val + 1];
  for(int i = 0; i < str.size(); i++){
    if (str[i] != delimiter)
      temp += str[i];
    else 
    {
      strSplit[index] = temp;
      index++;
      temp = "";
    }
  } 
  for(int i = 0; i < val + 1; i++){
    std::cout << strSplit[i] << ' ';
  }
  std::cout << "Finished\n";
  return strSplit;
}

void MatFrac::str2Frac(std::string * fracs, int size){
  std::stringstream ss;
  int num, den;
  matriz = new Fraction*[size];
  for(int i = 0; i < size; i++){
    matriz[i] = new Fraction[size];
    std::string * rowFracs = split(fracs[i], ' ');
    for(int j = 0; j < size; j++){
      std::string * temp = split(rowFracs[j], ' ');
      /* ss << temp[0];
      ss >> num;
      ss << temp[1];
      ss >> den;
      matriz[i][j] = Fraction(num, den);
      matriz[i][j].printFrac();
      std::cout << '\n'; */
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
  while (std::getline(matDoc, rawFrac))
    size++;
  rawFracs = new std::string[size];
  for(int i = 0; i < size; i++){
    std::getline(matDoc, rawFrac);
    rawFracs[i] = rawFrac;
  }
  matDoc.close();
  str2Frac(rawFracs, size);
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