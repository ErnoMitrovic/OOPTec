#include "cFraction.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

class MatFrac{
  Fraction ** matriz;
  int size;
  void str2Frac(std::string *, int);
  std::string * split(std::string, char);
  public :
    MatFrac(void);
    MatFrac(int);
    /*
    File format:
    x/x x/x x/x
    x/x x/x x/x
    x/x x/x x/x
    */
    MatFrac(std::string filepath);
    // Matrices MUST have same size
    void sumMats (MatFrac &, std::string);
    void printFracs(void);

    int getSize(void);
};