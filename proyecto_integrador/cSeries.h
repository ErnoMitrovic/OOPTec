#pragma once
#ifndef __SERIES
#define __SERIES
#include "cEpisode.h"
#include <vector>
using namespace std;

class Series{
  private:
    int id, length, rators;
    string name, genre;
    float rating;
    vector <Episode*> episodes;

  public:
    Series();
    Series(int _id, int _length, int _rators, string _name, string _genre, float _rating);
    Series(vector <Episode*> &, string);
    Series(string);
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