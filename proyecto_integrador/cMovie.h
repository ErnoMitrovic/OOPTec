#pragma once

#ifndef __MOVIE
#define __MOVIE
#include "cVideo.h"

using namespace std;

class Movie : public Video{
  public:
    Movie();
    Movie(int _id, string _name, int _length, string _genre, float _rating,int _rators);
    ~Movie();
    string toString(void) override;
    float getRating(void);
};

#endif