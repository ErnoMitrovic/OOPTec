#include "cMovie.h"

Movie::Movie(int _id, string _name, int _length, string _genre, float _rating,int _rators) : Video(_id, _length, _rators, _name, _genre, _rating) {}

Movie::Movie() : Video() {}

Movie::~Movie() {}

float Movie::getRating(){
  return Video::getRating();
}

string Movie::toString(){
  string info = Video::toString();
  info += "RATING: " + to_string(getRating()) + "\n";
  return info;
}