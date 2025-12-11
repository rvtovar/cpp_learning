#include "classes/Player.hpp"
#include <fmt/format.h>
import utilities;
int main()
{
    display_active_players();

    Player obj{"Rose", "Mage", 110, 55};

    display_active_players();

    {
        Player hero;
        display_active_players();
    }

    display_active_players();

    Player *enemy = new Player{"Greg", "Garlic Farmer", 100, 10};
    display_active_players();

    delete enemy;
    display_active_players();
    return 0;
}
