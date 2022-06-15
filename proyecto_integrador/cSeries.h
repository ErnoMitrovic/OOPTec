#pragma once
#ifndef __SERIES
#define __SERIES
#include "cEpisode.h"
#include <vector>
using namespace std;

class Series{
  private:
    vector <Episode*> episodes;
    string name;

  public:
    Series();
    Series(string);
    Series(vector <Episode*> &, string);
    ~Series();
    string toString(void);
    float avgRating(void);
    vector<Episode*> & getEpisodes(void);
    int getLength(void);
    string getGenre(void);
    string getName(void);
    void addEpisode(Episode *);
};

#endif