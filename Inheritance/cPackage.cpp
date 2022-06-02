#include "cPackage.hpp"

Package::Package(std::string * n, std::string * a, std::string * c, std::string * s, std::string * z, float stdC,
float l, float w, float d, float wei, float cp) 
: Shipping(n, a, c, s, z, stdC), length(l), width(w), depth(d) {
    weight = wei >= 0 ? wei : - wei;
    cpw = cp >= 0 ? cp : - cp;
}

Package::Package(float l, float w, float d, float wei, float cp) 
: Shipping(), length(l), width(w), depth(d), cpw(cp) {
    weight = wei >= 0 ? wei : - wei;
    cpw = cp >= 0 ? cp : - cp;
}

Package::Package() : Package(0, 0, 0, 0, 0) {}

Package::~Package(){}

std::string Package::toString(){
    std::string info = Shipping::toString();
    info += "LENGTH: " + std::to_string(length) + 
    "\nWIDTH: " + std::to_string(width) + 
    "\nDEPTH: " + std::to_string(depth) + 
    "\nWEIGTH: " + std::to_string(weight) +
    "\nCOST PER KG: " + std::to_string(cpw) + "\n";
    return info;
}

float Package::calculateCost(){
    float total = Shipping::calculateCost();
    total += cpw * weight;
    return total;
}