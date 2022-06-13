#pragma once

#ifndef __EPISODE
#define __EPISODE
#include "cVideo.h"

class Episode : public Video{
  private: 
    std::string title, season;
  public:
    Episode();
    Episode(int, int, int, std::string, std::string, float, std::string, std::string);
    ~Episode();
    std::string toString() override;
    float getRating();
};

#endif