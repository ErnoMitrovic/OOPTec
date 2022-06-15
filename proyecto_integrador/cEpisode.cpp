#include "cEpisode.h"

Episode::Episode(int _id, int _length, int _rators, string _name, string _genre, float _rating, string _title, string _season) : Video(_id, _length, _rators, _name, _genre, _rating), title(_title), season(_season) {}

Episode::Episode() : Video() {}

Episode::~Episode() {
  title.clear();
  season.clear();
}

float Episode::getRating(){
  return Video::getRating();
}

string Episode::toString(){
  string info = Video::toString();
  info += "RATING: " + to_string(getRating()) + "\n";
  return info;
}