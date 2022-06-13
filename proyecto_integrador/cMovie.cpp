#include "cMovie.h"

Movie::Movie(int _id, int _length, int _rators, std::string _name, std::string _genre, float _rating) : Video(_id, _length, _rators, _name, _genre, _rating) {}

Movie::Movie() : Video() {}

Movie::~Movie() {}

float Movie::getRating(){
  return Video::getRating();
}

std::string Movie::toString(){
  std::string info = Video::toString();
  info += "RATING: " + std::to_string(getRating()) + "\n";
  return info;
}