module;
#include <cctype> // For std::toupper
#include <fmt/format.h>
#include <iostream>
#include <string>

export module utilities;

import Movies;

using namespace std;

// Predefined colors for runtime console output
const string RED    = "\033[31m";
const string GREEN  = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE   = "\033[34m";
const string CYAN   = "\033[36m";
const string RESET  = "\033[0m"; // Reset color

// Simply output colorized text using std::cout
export void print_color(const string &text, const string &color)
{
    cout << color << text << RESET << endl;
}

// Enum for menu options
enum class MenuOption
{
    AddMovie,
    WatchMovie,
    ListMovies,
    Quit,
    Invalid
};

// Convert user input (char) to a MenuOption
MenuOption to_menu_option(char response)
{
    switch (std::toupper(response))
    {
    case 'A':
        return MenuOption::AddMovie;
    case 'W':
        return MenuOption::WatchMovie;
    case 'L':
        return MenuOption::ListMovies;
    case 'Q':
        return MenuOption::Quit;
    default:
        return MenuOption::Invalid;
    }
}

// Display menu options
void options()
{
    print_color("\nWelcome to Movie Tracker", CYAN);
    cout << string(40, '-') << endl;
    print_color("Please select an option:", YELLOW);
    print_color("Add a movie: A", GREEN);
    print_color("Watch a movie: W", GREEN);
    print_color("Display all movies: L", GREEN);
    print_color("Quit the Application: Q", RED);
    cout << string(40, '-') << endl;
    cout << endl; // Adds space for better readability
}
void add_movie(Movies &collection)
{
    string name, rating;
    int    watched;

    print_color("\n>> Adding a new movie", BLUE);
    cout << "Movie Name: ";
    cin >> name;

    cout << "Movie Rating: ";
    cin >> rating;

    cout << "Times watched: ";
    while (!(cin >> watched))
    {
        print_color("Invalid input. Please enter a valid integer for 'Times watched': ", RED);
        cin.clear();            // Clear the error state of cin
        cin.ignore(1000, '\n'); // Discard invalid input
    }

    if (collection.add_movie(name, rating, watched))
    {
        print_color("Movie added successfully!", GREEN);
    }
    else
    {
        print_color("Movie already exists. If you wish to increment its watch count, choose the "
                    "appropriate option.",
                    YELLOW);
    }
}
void watch_movie(Movies &collection)
{
    string name;

    print_color("\n>> Watching a movie", BLUE);
    cout << "Movie Name: ";
    cin >> name;

    if (collection.watch_movie(name))
    {
        print_color("Successfully watched the movie!", GREEN);
    }
    else
    {
        print_color("Movie does not exist in the collection. Add it first.", RED);
    }
}

// Logic handler for menu options
bool logic_run(MenuOption option, Movies &collection)
{
    cout << endl; // Add extra space before each option execution

    switch (option)
    {
    case MenuOption::AddMovie:
        add_movie(collection);
        break;
    case MenuOption::WatchMovie:
        watch_movie(collection);
        break;
    case MenuOption::ListMovies:
        print_color(">> Listing all movies", BLUE);
        collection.list_movies();
        break;
    case MenuOption::Quit:
        print_color("\n>> Quitting the application. Goodbye!", CYAN);
        return false;
    case MenuOption::Invalid:
    default:
        print_color("\nInvalid option selected. Please try again.", RED);
        break;
    }

    return true;
}

// Main runner for the application
export void runner()
{
    Movies collection;
    bool   use = true;
    char   response;

    print_color("-----------------------------------", CYAN);
    print_color("Welcome to the Movie Tracker App!", CYAN);
    print_color("-----------------------------------", CYAN);

    while (use)
    {
        options();
        cout << "Enter your choice: ";
        cin >> response;

        MenuOption option = to_menu_option(response);
        use               = logic_run(option, collection); // Execute the appropriate logic
    }

    print_color("\nThank you for using Movie Tracker!", CYAN);
}
