#include "cEpisode.h"

Episode::Episode(int _id, int _length, int _rators, std::string _name, std::string _genre, float _rating, std::string _title, std::string _season) : Video(_id, _length, _rators, _name, _genre, _rating), title(_title), season(_season) {}

Episode::Episode() : Video() {}

Episode::~Episode() {
  title.clear();
  season.clear();
}

float Episode::getRating(){
  return Video::getRating();
}

std::string Episode::toString(){
  std::string info = Video::toString();
  info += "RATING: " + std::to_string(getRating()) + "\n";
  return info;
}