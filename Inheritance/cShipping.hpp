#include <string>
class Shipping{
    private:
        std::string * name, * address, * city, * state, *zip;
        float stdCost;
    public:
        Shipping();
        Shipping(std::string *, std::string *, std::string *, std::string *, std::string *, float);
        ~Shipping();
        virtual float calculateCost(void);
        virtual std::string toString(void);
};