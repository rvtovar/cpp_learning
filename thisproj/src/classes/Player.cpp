#include "Player.hpp"
#include <fmt/format.h>
#include <string>

using namespace std;

Player::Player(string n_val, string j_val, int h_val, int xp_val)
    : name{n_val}, job{j_val}, health{h_val}, xp{xp_val}
{
}

Player::Player(string n_val) : Player{n_val, "Warrior", 100, 0} {}

Player::Player() : Player{"NPC", "Farmer", 10, 0} {}

string Player::get_name() const { return name; }

string Player::get_job() const { return name; }

void Player::set_name(string n_val) { name = n_val; }

void Player::set_job(string j_val) { job = j_val; }
