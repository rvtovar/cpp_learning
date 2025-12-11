#pragma once
#include <string>

using namespace std;

class Movie
{
  private:
    string name;
    string rating;
    int    watched;

  public:
    Movie(string n_val, string r_val, int w_val);
    const string &get_name() const;
    void          increment();
    string        display() const;
};
