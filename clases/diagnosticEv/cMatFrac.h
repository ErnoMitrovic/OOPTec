#include "cFraction.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

class MatFrac{
  Fraction ** matriz;
  int size;
  void str2Frac(std::string *);
  std::string * split(std::string, std::string delimiter);
  public :
    MatFrac(void);
    MatFrac(int);
    ~MatFrac();
    /*
    File format:
    x/x x/x x/x
    x/x x/x x/x
    x/x x/x x/x
    */
    MatFrac(std::string filepath);
    // Matrices MUST have same size
    void sumMats (MatFrac *, const std::string);
    void printFracs(void);

    int getSize(void);
    void debug();
};