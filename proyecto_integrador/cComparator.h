#pragma once
#ifndef __COMPARATOR
#define __COMPARATOR
#include <iostream>
#include <exception>
using namespace std;
template <class C, class T>
class Comparator{
  private:
    C toCompare;
  public:
    Comparator(C tC) : toCompare(tC){}
    bool operator()(const T & comparable) const {
      bool cond;
      try{
        cond = comparable -> getName() == toCompare; 
      } catch(exception e){
        cerr<<"Not comparable! " << e.what() << "\n";
        return false;
      }
      return cond;
    }
};
#endif