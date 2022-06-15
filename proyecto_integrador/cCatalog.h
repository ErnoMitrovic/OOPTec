#pragma once
#include "cSeries.h"
#include "cMovie.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Catalog{
  private:
    vector <Movie*> movies;
    vector <Series*> series;

    vector <string> split(string original, string delimiter);
    vector <string> readFileToStringVector(string filename);
    int stringToInt(string s);
    float stringToFloat(string s);
  public:

    Catalog();
    Catalog(string filename);
    ~Catalog();

    void showByGenre(string);
    void showByRating(float);
    void showMoviesByRating(float);
    void showEpisodesByRating(float, Series);
    void rateVideo(float, int);
    void menu();
    
};
