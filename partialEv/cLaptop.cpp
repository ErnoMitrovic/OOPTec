#include "cLaptop.hpp"

/*
private:
    std::string mobileGPU;
public:
    Laptop();
    Laptop(int, std::string);
    ~Laptop();
    std::string toString() override;
    int getRam() override;
*/

/**
 * @brief Construct a new Laptop object
 * 
 * @param _ram The ram of this Laptop
 * @param _mobileGPU The name of the mobile GPU
 */
Laptop::Laptop(int _ram, std::string _mobileGPU) : PC(_ram), mobileGPU(_mobileGPU){}

/**
 * @brief Construct a new Laptop object with 16 RAM GB and mobile GPU "GTX2080M"
 * 
 */
Laptop::Laptop() : Laptop(16, "GTX2080M") {}

/**
 * @brief Destroy the Laptop object
 * 
 */
Laptop::~Laptop() {}

/**
 * @brief Getter for ram
 * 
 * @return int the ram allocated for this Laptop
 */
int Laptop::getRam(){
    return ram;
}

/**
 * @brief The information of this Laptop in the form of a string
 * 
 * @return std::string information
 */
std::string Laptop::toString(){
    std::string info = "";
    info += "I'm a Laptop!\t\tRAM: " + std::to_string(getRam())
    + " GB\t\tMOBILE GPU: " + mobileGPU + "\n";
    return info;
}