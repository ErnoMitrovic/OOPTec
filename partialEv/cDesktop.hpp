#include "cPC.hpp"

class Desktop : public PC{
    private:
        std::string GPU;
    public:
        Desktop();
        Desktop(int, std::string);
        ~Desktop();
        std::string toString(void) override;
        int getRam(void) override;
};