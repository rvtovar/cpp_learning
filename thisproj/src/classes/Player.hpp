#pragma once
#include <string>
using namespace std;
class Player
{
  private:
    string name;
    int    health;
    int    xp;
    string job;

  public:
    string get_name() const;
    string get_job() const;

    void set_name(string n_val);
    void set_job(string j_val);

    // Overloaded Constructors
    Player();
    Player(string n_val);
    Player(string n_val, string j_val, int h_val, int xp_val);
};
