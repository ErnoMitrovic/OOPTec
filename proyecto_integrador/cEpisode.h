#pragma once

#ifndef __EPISODE
#define __EPISODE
#include "cVideo.h"
using namespace std;

class Episode : public Video{
  private: 
    string title, season;
  public:
    Episode();
    Episode(int, int, int, string, string, float, string, string);
    ~Episode();
    string toString(void) override;
    float getRating(void);
};

#endif