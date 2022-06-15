#include "cVideo.h"

// TODO: documentacion

Video::Video(int _id, int _length, int _rators, string _name, string _genre, float _rating)
: id(_id), length(_length), rators(_rators), name(_name), genre(_genre), rating(_rating) {}

Video::Video() : Video(1, 20, 10, "DEF", "DEF", 3.f) {}

Video::~Video() {
  name.clear();
  genre.clear();
}

string Video::toString(){
  string info = "";
  info += "ID: " + to_string(id) + "\n" 
    + "LENGTH: " + to_string(length) + " min\n"
    + "RATORS: " + to_string(rators) + "\n"
    + "NAME: " + name + "\n"
    + "GENRE: " + genre + "\n";
  return info;
}

string Video::getName(){
  return name;
}

string Video::getGenre(){
  return genre;
}

float Video::getRating(){
  return rating;
}

void Video::setRating(float _rt){
  rators++;
  rating = (rating + _rt) / 2.;
}

void Video::setRating(float _rt, int _rators){
  rators += _rators;
  rating = (rating + _rt) / ((float) (_rators+1));
}

int Video::operator +(const Video & v){
  return rating + v.rating;
}