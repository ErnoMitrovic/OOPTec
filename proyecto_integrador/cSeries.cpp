#include "cSeries.h"

Series::Series(std::vector <Episode*> & eps, std::string _name) : episodes(eps), name(_name){}

Series::Series(std::string _name) : name(_name) {}

Series::Series(): Series("DEF"){}

Series::~Series(){
  episodes.clear();
  name.clear();
}

std::string Series::toString(){
  std::string info = "";
  for(std::vector<Episode*>::iterator i = episodes.begin(); i != episodes.end(); i++){
    info += (*i) -> toString();
  }
  return info;
}

int Series::getLength(){
  return episodes.size();
}

float Series::avgRating(){
  float rt = 0;
  for(std::vector<Episode*>::iterator i = episodes.begin(); i != episodes.end(); i++){
    rt += (*i) -> getRating();
  }
  rt /= getLength();
  return rt;
}

std::vector <Episode*> & Series::getEpisodes(){
  return episodes;
}

std::string Series::getGenre(){
  return episodes[0]->getGenre();
}

std::string Series::getName(){
  return name;
}