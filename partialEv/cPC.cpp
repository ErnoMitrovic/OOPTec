#include "cPC.hpp"

/**
 * @brief Construct a new PC object
 * 
 * @param _ram the ram that this PC will allocate
 */
PC::PC(int _ram) : ram(_ram){}

/**
 * @brief Construct a new PC object
 * 
 */
PC::PC() : PC(0){}

/**
 * @brief Destroy the PC object
 * 
 */
PC::~PC() {}

/**
 * @brief Sets the ram of the PC
 * 
 * @param _ram 
 */
void PC::setRam(int _ram){
    ram = _ram;
}

/**
 * @brief Adds the ram of two PC
 * 
 * @param aPC the other PC
 * @return int the addition of both ram
 */
int PC::operator+ (const PC & aPC){
    return ram + aPC.ram;
}