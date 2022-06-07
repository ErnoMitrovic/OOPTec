#include <cmath>
#include <string>

class Polar{
  private:
    double r, ang;
  public:
    Polar();
    Polar(double r, double ang);
    std::string toString(void);
    Polar operator + (const Polar &);
};