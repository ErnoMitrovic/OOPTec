#include "cDesktop.hpp"

/*
private:
        std::string GPU;
    public:
        Desktop();
        Desktop(int, std::string);
        ~Desktop();
        std::string toString(void) override;
        int getRam(void) override;
*/

/**
 * @brief Construct a new Desktop object
 * 
 * @param _ram the ram of the desktop computer
 * @param _GPU GPU name of the desktop computer
 */
Desktop::Desktop(int _ram, std::string _GPU) : PC(_ram), GPU(_GPU) {}

/**
 * @brief Construct a new Desktop object with 32 GB of ra and GPU "RTX2080"
 * 
 */
Desktop::Desktop() : Desktop(32, "RTX2080") {}

/**
 * @brief Destroy the Desktop:: Desktop object
 * 
 */
Desktop::~Desktop(){}

int Desktop::getRam(){
    return ram;
}

/**
 * @brief The information of the Desktop in the form of a string
 * 
 * @return std::string information
 */
std::string Desktop::toString(){
    std::string info = "";
    info += "I'm a Desktop!\t\tRAM: " + std::to_string(getRam())
    + " GB\t\tGPU: " + GPU + "\n";
    return info;
}