 #include "cCatalog.h"

  Catalog::Catalog(){
      movies.push_back(new Movie());
      cout << movies.at(0)->toString();
  };

    vector <string> Catalog::readFileToStringVector(string filename){
      vector<string> lines;
      fstream theFile;
      theFile.open(filename, ios::in);
      if(theFile.is_open()){
        string line;
        while(getline(theFile, line)){
          lines.push_back(line);
        }
      }
      theFile.close();
      return lines;
    }

vector <string> Catalog::split(string original, string delimiter){
      vector<string> splitted;
      size_t pos = 0;
      string token;
      while((pos = original.find(delimiter))!=string::npos){
        token = original.substr(0,pos);
        splitted.push_back(token);
        original.erase(0, pos + delimiter.length());
      }
      splitted.push_back(original);
      return splitted;
    }

    int Catalog::stringToInt(string s){
      int n = 0;
      stringstream ssn;
      ssn << s;
      ssn >> n;
      return n;
    }

    float Catalog::stringToFloat(string s){
      float n = 0;
      stringstream ssn;
      ssn << s;
      ssn >> n;
      return n;
    }

  Catalog::Catalog(string filename){
      vector<string> lines = readFileToStringVector(filename);
    cout << "READ " << to_string(lines.size()) << " LINES." << endl;
    vector<string>::iterator it;
    for(it = lines.begin()+1; it != lines.end(); ++it){
      string line = (*it);
      vector<string> parts = split(line, ", ");
      if(parts.size()==10){
        int id = stringToInt(parts[0]);
        string name = parts[1];
        int length = stringToInt(parts[2]);
        string genre = parts[3];
        float rating = stringToFloat(parts[4]);
        int raters = stringToInt(parts[5]);
        string seriesOrMovie = parts[6];
        int episode = stringToInt(parts[7]);
        string title = parts[8];
        int season = stringToInt(parts[9]);

        if (seriesOrMovie == "Movie"){
          Movie* mov = new Movie(id,name,length,genre,rating,raters);
          movies.push_back(mov);
        } else if (seriesOrMovie == "Series"){
          vector<Series*>::iterator itS;
          itS = find_if(series.begin(), series.end(), Comparator<string, Series*>(name));
          if (itS != series.end()){
// Episode(int _id, int _length, int _rators, string _name, string _genre, float _rating, int _episode, string _title, string _season)
            Episode* epi = new Episode(id, length, raters, name, genre, rating, episode, title, season);
            (*itS) ->addEpisode(epi);
          } else if (itS == series.end()){
            Series * s = new Series(id, length, raters, name, genre, rating);
            s->addEpisode(new Episode(id, length, raters, name, genre, rating, episode, title, season));
            series.push_back(s);
          }
        }
      }
    }
  };

  Catalog::~Catalog(){
    movies.clear();
    series.clear();
  };



    void Catalog::showByGenre(string genre){
      cout << "EPISODES:\n";
      for(auto it = series.begin(); it < series.end(); it++){
        if((*it)->getGenre() == genre)
          cout << (*it)->toString();
      }
      cout << "MOVIES:\n";
      for(auto it = movies.begin(); it < movies.end(); it++){
        if((*it)->getGenre() == genre)
          cout << (*it)->toString();
      }
    }

    void Catalog::showByRating(float rating){
      cout << "EPISODES:\n";
      vector<Episode*> episodes;
      for(auto it = series.begin(); it<series.end(); it++){
        episodes = (*it)->getEpisodes();
        for(auto jt = episodes.begin(); jt < episodes.end(); jt++){
          if((*jt)->getRating() == rating)
            cout << (*jt)->toString();
        }
      }
      cout << "MOVIES:\n";
      for(auto it = movies.begin(); it < movies.end(); it++){
        if((*it)->getRating() == rating)
          cout << (*it)->toString();
      }
    }

    void Catalog::showMoviesByRating(float rating){
      for(auto it = movies.begin(); it < movies.end(); it++){
        if((*it)->getRating() == rating)
          cout << (*it)->toString();
      }
    }

    void Catalog::showEpisodesByRating(float rating, string seriesName){
      vector <Episode*> episodes;
      auto it = series.begin();
      while(it != series.end()){
        it = find_if(it, series.end(), Comparator<string, Series*>(seriesName));
        if(it != series.end()){
          episodes = (*it)->getEpisodes();
          for(auto jt = episodes.begin(); jt != episodes.end(); jt++){
            if((*jt)->getRating() == rating)
              cout << (*jt)->toString();
          }
        }
      }
    }

    void Catalog::rateVideo(string title, float rating){
      auto it = find_if(movies.begin(), movies.end(), Comparator<string, Movie*>(title));
      if(it != movies.end()){
        (*it)->setRating(rating);
        return;
      }
      vector <Episode*> * episodes;
      for(auto itS = series.begin(); itS != series.end(); itS++){
        for(auto itE = (*itS)->getEpisodes().begin(); itE != (*itS)->getEpisodes().end(); itE++){
          if((*itE)->getTitle() == title){
            (*itE)->setRating(rating);
            return;
          }
        }
      }
    }

    void Catalog::menu(){
      
    }

