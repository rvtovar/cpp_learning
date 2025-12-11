#include "Player.hpp"
#include <fmt/format.h>
#include <string>

using namespace std;

int Player::num_players = 0;

int Player::get_num_players() { return num_players; }

Player::Player(string n_val, string j_val, int h_val, int xp_val)
    : name{n_val}, job{j_val}, health{h_val}, xp{xp_val}
{
    ++num_players;
}

Player::Player() : Player{"Default", "Farmer", 10, 0} {}

Player::~Player() { --num_players; }
