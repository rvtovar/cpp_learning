#include "classes/Player.hpp"
#include <fmt/format.h>
import utilities;

void display_player_name(const Player &p) { fmt::println("Player: {}", p.get_name()); }
int  main()
{
    const Player villian{"Villian", "Mage", 100, 55};
    Player       hero{"Hero", "Spellblade", 110, 55};

    display_player_name(villian);
    display_player_name(hero);

    return 0;
}
