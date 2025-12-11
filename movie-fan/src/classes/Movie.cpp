#include "Movie.hpp"
#include <fmt/format.h>
#include <string>

using namespace std;

Movie::Movie(string n_val, string r_val, int w_val) : name{n_val}, rating{r_val}, watched{w_val}
{
    fmt::println("New Movie: {} created", name);
}

void Movie::increment() { ++watched; }

const string &Movie ::get_name() const { return name; }
string        Movie::display() const
{
    return fmt::format("Name: {}, Rating: {}, Times Watched: {}", name, rating, watched);
}
