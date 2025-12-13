#include <fmt/format.h>
import utilities;

#include "classes/MyString.hpp"

using namespace std;
int main()
{
    MyString empty;
    MyString larry("larry");
    MyString stooge{larry};

    empty.display();
    larry.display();
    stooge.display();

    empty = larry;
    empty.display();

    empty = "This is a test";
    empty.display();

    fmt::println("Move Assignment");

    MyString a{"Hello"};

    a.display();
    a = MyString{"Hola"};
    a.display();

    a = "Bonjour";

    a.display();

    return 0;
}
