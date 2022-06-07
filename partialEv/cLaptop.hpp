#include "cPC.hpp"

class Laptop : public PC
{
private:
    std::string mobileGPU;
public:
    Laptop();
    Laptop(int, std::string);
    ~Laptop();
    std::string toString(void) override;
    int getRam(void) override;
};