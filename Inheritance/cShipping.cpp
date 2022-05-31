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
}