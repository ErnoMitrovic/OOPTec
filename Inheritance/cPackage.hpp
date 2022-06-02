#include "cShipping.hpp"

class Package : public Shipping
{
private:
    float length, width, depth, weight, cpw;
public:
    Package();
    Package(float, float, float, float, float);
    Package(std::string *, std::string *, std::string *, std::string *,
    std::string *, float, float, float, float, float, float);
    ~Package();
    std::string toString() override;
    float calculateCost() override;
};