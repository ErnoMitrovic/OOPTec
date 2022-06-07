#include <string>

class PC{
    public:
        int ram;
        PC();
        PC(int);
        virtual std::string toString();
        virtual int getRam(void);
        void setRam(int);
};