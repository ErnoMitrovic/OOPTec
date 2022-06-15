 #include "cCatalog.h"

  Catalog::Catalog(){
      movies.push_back(new Movie());
      cout << movies.at(0)->toString();
  };

  Catalog::Catalog(string filename){
      vector<string> lines = readFileToStringVector("Data.csv");
    cout << "READ " << to_string(lines.size()) << " LINES." << endl;
    vector<string>::iterator it;
    for(it = lines.begin(); it != lines.end(); ++it){
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
        string episode = parts[7];
        string title = parts[8];
        int season = stringToInt(parts[9]);

        if (seriesOrMovie == "Movie"){
          Movie* mov = new Movie(id,name,length,genre,rating,raters);
          movies.push_back(mov);
        } else if (seriesOrMovie == "Series"){
          vector<Series*>::iterator itS;
          itS = find(series.begin(), series.end(), name);
          if (itS != series.end()){
            Episode* epi = new Episode(id,name,length,genre,rating,raters,);
            (*itS) ->addEpisode(epi);
          } else if (itS == series.end()){
            series.push_back(new Series());
            Episode* epi = new Episode();
          }
        }
      }
    }
  };

  Catalog::~Catalog(){
    movies.clear();
    series.clear();
  };

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


    void Catalog::showByGenre(string){
      
    }

    void Catalog::showByRating(float){
      
    }

    void Catalog::showMoviesByRating(float){
      
    }

    void Catalog::showEpisodesByRating(float, Series){
      
    }

    void Catalog::rateVideo(float, int){
      
    }

    void Catalog::menu(){
      
    }

