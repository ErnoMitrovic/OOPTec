#include "cPC.hpp"

class Laptop : public PC
{
private:
    std::string mobileGPU;
public:
    Laptop();
    Laptop(int, std::string);
    ~Laptop();
    std::string toString() override;
    int getRam() override;
};