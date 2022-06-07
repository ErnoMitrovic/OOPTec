#pragma once
#include <string>

class PC{
    public:
        int ram;
        PC();
        PC(int);
        ~PC();
        virtual std::string toString() = 0;
        virtual int getRam(void) = 0;
        void setRam(int);
};