#include "cDatacenter.hpp"
#include <iostream>

int main(){
    Datacenter * dc = new Datacenter(5, 5);
    std::cout << dc->toString() << std::endl;
    std::cout << "TOTAL RAM: " << dc->computeTotalRam() << " GB" << std::endl;
}