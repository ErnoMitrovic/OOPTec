#include "cLaptop.hpp"
#include "cDesktop.hpp"
#include <vector>

class Datacenter
{
private:
    std::vector<PC*> computers;
public:
    Datacenter();
    Datacenter(int nLaptop, int nDesktop);
    ~Datacenter();
    int computeTotalRam(void);
    std::string toString(void);
};