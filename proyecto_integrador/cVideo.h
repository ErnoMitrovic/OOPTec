#pragma once

#ifndef __VIDEO
#define __VIDEO
#include <string>

class Video{
  private:
    int id, length, rators;
    std::string name, genre;
    float rating;
  protected:
    Video();
    Video(int, int, int, std::string, std::string, float);
    ~Video();
  public:
    virtual std::string toString(void) = 0;
    std::string getName(void);
    virtual float getRating(void);
    void setRating(float rating, int rators);
};

#endif