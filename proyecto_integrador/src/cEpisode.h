#pragma once

#ifndef __EPISODE
#define __EPISODE
#include "cVideo.h"
using namespace std;

class Episode : public Video{
  private: 
    int episode, season;
    string title;
  public:
    Episode();
    Episode(int, int, int, string, string, float, int, string, int);
    ~Episode();
    string toString(void) override;
    float getRating(void);
    string getTitle(void);
};

#endif