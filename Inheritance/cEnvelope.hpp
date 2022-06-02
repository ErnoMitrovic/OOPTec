#include "cShipping.hpp"

class Envelope : public Shipping
{
private:
    float charge, length, width;
public:
    Envelope();
    Envelope(float, float, float);
    Envelope(std::string *, std::string *, std::string *, std::string *, std::string *, float, float, float, float);
    ~Envelope();
    std::string toString(void) override;
    float calculateCost(void) override;
};