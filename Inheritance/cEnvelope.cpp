#include "cEnvelope.hpp"

Envelope::Envelope(std::string * n, std::string * a, std::string * c, std::string * s, std::string * z, float stdC,
float l, float w, float ch) : Shipping(n, a, c, s, z, stdC) {
    length = l > 0 ? l : -l;
    width = w > 0 ? w : -w;
    charge = ((l > 30 && w > 25) || (w > 30 && l > 25)) ? ch : 0;
}

Envelope::Envelope(float l, float w, float ch) : Shipping(), length(l), width(w) {
    length = l > 0 ? l : -l;
    width = w > 0 ? w : -w;
    charge = ((l > 30 && w > 25) || (w > 30 && l > 25)) ? ch : 0;
}

Envelope::Envelope() : Envelope(5, 5, 5){}

Envelope::~Envelope() {}

std::string Envelope::toString(){
    std::string info = Shipping::toString();
    info += "LENGTH: " + std::to_string(length) + 
    "\nWIDTH: " + std::to_string(width) + 
    "\nCHARGE: " + std::to_string(charge) + "\n";
    return info;
}

float Envelope::calculateCost(){
    return Shipping::calculateCost() + charge;
}