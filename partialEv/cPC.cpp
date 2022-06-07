#include "cPC.hpp"

/*
        int ram;
        PC();
        PC(int);
        std::string toString();
        int getRam(void);
        void setRam(int);
*/

/**
 * @brief Construct a new PC::PC object
 * 
 * @param _ram the ram that this PC will allocate
 */
PC::PC(int _ram) : ram(_ram){}

/**
 * @brief Construct a new PC object
 * 
 */
PC::PC() : PC(0){}

void PC::setRam(int _ram){
    ram = _ram;
}
