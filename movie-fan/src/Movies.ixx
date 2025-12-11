module;
#include "classes/Movie.hpp"
#include <algorithm>
#include <fmt/format.h>
#include <functional>
#include <optional> // Used for movie_check
#include <string>
#include <vector>

export module Movies;

using namespace std;

export class Movies
{
  private:
    std::vector<Movie>                 movies;
    optional<reference_wrapper<Movie>> movie_check(const std::string &name);

  public:
    bool add_movie(std::string name, std::string rating, int watched);
    bool watch_movie(std::string name);
    void list_movies();
};
// For std::reference_wrapper

optional<std::reference_wrapper<Movie>> Movies::movie_check(const string &name)
{
    auto it = std::find_if(movies.begin(), movies.end(),
                           [&name](Movie &movie) { return movie.get_name() == name; });
    if (it != movies.end())
    {
        return *it; // Return reference to the Movie object
    }
    return std::nullopt;
}

bool Movies::add_movie(std::string name, std::string rating, int watched)
{
    const auto result = movie_check(name);
    if (result)
    {
        return false;
    }
    movies.push_back(Movie{name, rating, watched});
    return true;
}

bool Movies::watch_movie(std::string name)
{
    auto result = movie_check(name);

    if (result)
    {
        result->get().increment();
        return true;
    }
    return false;
}

void Movies::list_movies()
{
    for (const auto &movie : movies)
    {
        fmt::print("{}\n", movie.display());
    }
}
