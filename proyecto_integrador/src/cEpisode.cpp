#include "cEpisode.h"

Episode::Episode(int _id, int _length, int _rators, string _name, string _genre, float _rating, int _episode, string _title, int _season) : Video(_id, _length, _rators, _name, _genre, _rating), episode(_episode), title(_title), season(_season) {}

Episode::Episode() : Video() {}

Episode::~Episode() {
  title.clear();
}

float Episode::getRating(){
  return Video::getRating();
}

string Episode::toString(){
  string info = Video::toString();
  info += "RATING: " + to_string(getRating()) + "\n" + 
    "EPISODE: " + to_string(episode) + "\n" +
    "TITLE: " + title + "\n" +
    "SEASON: " + to_string(season) + "\n";
  return info;
}

string Episode::getTitle(){
  return title;
}
