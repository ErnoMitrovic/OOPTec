#include "cShipping.hpp"

Shipping::Shipping(std::string * n, std::string * a, std::string * c, std::string * s, std::string * z, float stdC)
: name(n), address(a), city(c), state(s), zip(z), stdCost(stdC) {}

Shipping::Shipping() 
: Shipping(new std::string[2], new std::string[2], new std::string[2], new std::string[2], new std::string[2], 0)
{}

Shipping::~Shipping(){
    delete name, address, city, state, zip;
}

std::string Shipping::toString(){
    std::string info = "";
    info += "- SHIPPER INFO -\n";
    info += "NAME: " + name[0] +  "\nADDRESS:" + address[0] + "\nCITY: " + city[0] +
    "\nSTATE: " + state[0] + "\nZIP: " + zip[0];
    info += "- RECEIVER INFO -\n";
    info += "NAME: " + name[1] +  "\nADDRESS:" + address[1] + "\nCITY: " + city[1] +
    "\nSTATE: " + state[1] + "\nZIP: " + zip[1];
    info += "\nSTANDARD COST: " + std::to_string(stdCost) + "\n";
    return info;
}

float Shipping::calculateCost(){
    return stdCost;
}