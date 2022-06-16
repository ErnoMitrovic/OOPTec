#pragma once

#ifndef __VIDEO
#define __VIDEO
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Video{
  private:
    int id, length, rators;
    string name, genre;
    float rating;
  protected:
    Video();
    Video(int, int, int, string, string, float);
    ~Video();
  public:
    virtual string toString(void) = 0;
    string getName(void);
    virtual float getRating(void);
    void setRating(float);
    void setRating(float rating, int rators);
    int operator + (const Video &);
    string getGenre(void);
    int getRators(void);
};
#endif