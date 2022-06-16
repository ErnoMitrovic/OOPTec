#include "cVideo.h"

// TODO: documentacion

Video::Video(int _id, int _length, int _rators, string _name, string _genre, float _rating)
: id(_id), length(_length), rators(_rators), name(_name), genre(_genre), rating(_rating) {}

Video::Video() : Video(0, 0, 0, "DEF", "DEF", 0.f) {}

Video::~Video() {
  name.clear();
  genre.clear();
}

int Video::getRators(){
  return rators;
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
  rating = (rators*rating + _rt) * ((float)1/(rators+1));
  rators++;
}

void Video::setRating(float _rt, int _rators){
  rating = (rators*rating + _rt*_rators) * ((float) (1/(_rators+rators)));
  rators += _rators;
}

int Video::operator +(const Video & v){
  rating += v.rating;
  return rating;
}
