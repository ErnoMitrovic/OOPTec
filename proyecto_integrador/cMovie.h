#pragma once

#ifndef __MOVIE
#define __MOVIE
#include "cVideo.h"

class Movie : public Video{
  public:
    Movie();
    Movie(int, int, int, std::string, std::string, float);
    ~Movie();
    std::string toString(void) override;
    float getRating(void);
};

#endif