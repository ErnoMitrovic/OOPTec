#include "cSeries.h"

Series::Series(vector <Episode*> & eps, string _name) : episodes(eps), name(_name){}

Series::Series(int _id, int _length, int _rators, string _name, string _genre, float _rating) : id(_id), length(_length), rators(_rators), name(_name), genre(_genre), rating(_rating) {}

Series::Series(string _name) : name(_name) { }

Series::Series() : Series("DEF"){}

Series::~Series(){
  episodes.clear();
  name.clear();
}

string Series::toString(){
  string info = "";
  info += "SERIES NAME: " + name + "\n"
    + "SERIES GENRE: " + getGenre() + "\n"
    + "SERIES LENGTH: " + to_string(getLength()) + "\n"
    + "SERIES RATING: " + to_string(avgRating()) + "\n"+
    "-- EPISODES --\n"; 
  for(vector<Episode*>::iterator i = episodes.begin(); i != episodes.end(); i++){
    info += (*i) -> toString();
  }
  return info;
}

int Series::getLength(){
  return episodes.size();
}
float Series::avgRating(){
  Episode e;
  for(auto i = episodes.begin(); i != episodes.end(); i++){
    e+*(*i);
  }
  return e.getRating()/((float) getLength());
}

vector <Episode*> & Series::getEpisodes(){
  return episodes;
}

string Series::getGenre(){
  return episodes[0]->getGenre();
}

string Series::getName(){
  return name;
}

void Series::addEpisode(Episode * ep){
  episodes.push_back(ep);
}