module;
#include "classes/Player.hpp"
#include <fmt/format.h>
export module utilities;

export int add(int a, int b) { return a + b; }

export void greet() { fmt::println("Hello from the utilities module!"); }

export void display_active_players()
{
    fmt::println("Active Players : {}", Player::get_num_players());
}
