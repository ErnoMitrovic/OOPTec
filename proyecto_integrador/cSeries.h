#pragma once
#ifndef __SERIES
#define __SERIES
#include "cEpisode.h"
#include <vector>

class Series{
  private:
    std::vector <Episode*> episodes;
    std::string name;
  public:
    Series();
    Series(std::string);
    Series(std::vector <Episode*> &, std::string);
    ~Series();
    std::string toString(void);
    float avgRating(void);
    std::vector<Episode*> & getEpisodes(void);
    int getLength(void);
    std::string getGenre(void);
    std::string getName(void);
};

#endif