#pragma once
#include <fmt/format.h>
#include <string>

using namespace std;

class Player
{
  private:
    static int num_players;
    string     name;
    string     job;
    int        health;
    int        xp;

  public:
    Player();
    Player(string name, string job, int health, int xp);
    static int get_num_players();

    // Destructor
    ~Player();
};
