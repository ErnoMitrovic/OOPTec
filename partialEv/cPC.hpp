#pragma once
#include <string>

class PC{
    public:
        int ram;
        PC();
        PC(int);
        ~PC();
        virtual std::string toString();
        virtual int getRam(void);
        void setRam(int);
};