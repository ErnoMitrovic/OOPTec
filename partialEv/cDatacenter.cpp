#include "cDatacenter.hpp"

/*
class Datacenter
{
private:
    std::vector<PC*> computers;
public:
    Datacenter();
    Datacenter(int nLaptop, int nDesktop);
    ~Datacenter();
    int computeTotalRam(void);
    std::string toString(void);
};
*/

/**
 * @brief Construct a new Datacenter object
 * 
 * @param nLaptop number of Laptop
 * @param nDesktop number of Desktop computers
 */
Datacenter::Datacenter(int nLaptop, int nDesktop){
    for(unsigned short i = 0; i < nLaptop + nDesktop; i++){
        if(i < nLaptop) 
            computers.push_back(new Laptop());
        else
            computers.push_back(new Desktop());
    }
}

/**
 * @brief Construct a new Datacenter object with 4 laptops and 4 desktop computers
 * 
 */
Datacenter::Datacenter() : Datacenter(4,4){}

/**
 * @brief Destroy the Datacenter object
 * 
 */
Datacenter::~Datacenter() {}

/**
 * @brief Sums the total ram of all the computers
 * 
 * @return int total ram of the Datacenter
 */
int Datacenter::computeTotalRam(){
    Laptop dummie(0, "DEF");
    for(std::vector<PC*>::iterator it = computers.begin(); it != computers.end(); it++){
        dummie.setRam(dummie + *(*it));
    }
    return dummie.getRam();
}

std::string Datacenter::toString(){
    std::string info = "I'm a Datacenter!\n";
    for(std::vector<PC*>::iterator it = computers.begin(); it != computers.end(); it++){
        info += (*it)->toString();
    }
    return info;
}