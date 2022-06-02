#include "cEnvelope.hpp"
#include "cPackage.hpp"

#include <iostream>

namespace testCases{
    using namespace std;

    /**
     * @brief Default everything, in toString() should only print envelope and package data
     * 
     */
    void first(){
        Envelope * e = new Envelope();
        Package * p = new Package();
        cout << e->toString();
        cout << p->toString();
        cout << "Cost envelope: " << e->calculateCost() << endl;
        cout << "Cost package: " << p->calculateCost() << endl;
        delete e, p;
    }

    /**
     * @brief Second constructor, no info is set for Shipping
     * 
     */
    void second(){
        Package * p = new Package(30.f, 20.f, 50.f, 25.f, 6.f);
        Envelope * e = new Envelope(21.f, 31.f, 30.f);
        cout << e->toString();
        cout << p->toString();
        cout << "Cost envelope: " << e->calculateCost() << endl;
        cout << "Cost package: " << p->calculateCost() << endl;
        //Exceeds dimensions
        e = new Envelope(32.f, 31.f, 30.f);
        cout << e->toString();
        cout << "Cost envelope: " << e->calculateCost() << endl;
        delete e, p;
    }
    /**
     * @brief Third constructor of all of them, same data as in second
     * 
     */
    void third(){
        string * name = new string[2] {"Jorge", "Benito"}, 
        * address = new string[2] {"Avenida Revolucion 81", "El Salto 241"},
        * city = new string[2] {"Benito Juarez", "Ciudad Victoria"}, 
        * state = new string[2] {"Ciudad de Mexico", "Tamaulipas"}, 
        * zip = new string[2] {"16563", "12415"};
        float stdCost = 45;
        Package * p = new Package(name, address, city, state, zip, stdCost, 30.f, 20.f, 50.f, 25.f, 6.f);
        Envelope * e = new Envelope(name, address, city, state, zip, stdCost, 21.f, 31.f, 30.f);
        cout << e->toString();
        cout << p->toString();
        cout << "Cost envelope: " << e->calculateCost() << endl;
        cout << "Cost package: " << p->calculateCost() << endl;
        //Exceeds dimensions
        e = new Envelope(name, address, city, state, zip, stdCost, 32.f, 31.f, 30.f);
        cout << e->toString();
        cout << "Cost envelope: " << e->calculateCost() << endl;
        delete e, p;
    }

    /**
     * @brief It checks any error handling
     * 
     */
    void special(){
        string * name = new string[2] {"Jorge", "Benito"}, 
        * address = new string[2] {"Avenida Revolucion 81", "El Salto 241"},
        * city = new string[2] {"Benito Juarez", "Ciudad Victoria"}, 
        * state = new string[2] {"Ciudad de Mexico", "Tamaulipas"}, 
        * zip = new string[2] {"16563", "12415"};
        float stdCost = 45;
        Package * p = new Package(name, address, city, state, zip, stdCost, 30.f, 20.f, 50.f, -45.f, 0.f);
        Envelope * e = new Envelope(name, address, city, state, zip, stdCost, -28.f, 40.f, 30.f);
        cout << e->toString();
        cout << p->toString();
        cout << "Cost envelope: " << e->calculateCost() << endl;
        cout << "Cost package: " << p->calculateCost() << endl;
    }
}

void menu(){
    short sel;
    do{
        std::cout << "Test 1: all default\n"
        << "Test 2: Try second constructor that handles package and envelope data, no shipping\n"
        << "Test 3: Handles all data\n"
        << "Test 4: Checks errors\n" ;
        std::cout << "Select case (1-4): ";
        std::cin >> sel;
        switch(sel){
            case 1:
                testCases::first();
                break;
            case 2:
                testCases::second();
                break;
            case 3:
                testCases::third();
                break;
            case 4:
                testCases::special();
                break;
            default:
                std::cout << "Invalid input\n";
                break;
        }
    } while(sel < 1 || sel > 4);
}

int main(){
    menu();
    return 0;
}