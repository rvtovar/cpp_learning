#include "MyString.hpp"
#include <cstring>
#include <fmt/format.h>
#include <string>

MyString::MyString() : str{nullptr}
{
    str  = new char[1];
    *str = '\0';
}

// Overloaded Con
//
MyString::MyString(const char *s) : str{nullptr}
{
    if (s == nullptr)
    {
        str  = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// Copy
//
MyString::MyString(const MyString &source) : str{nullptr}
{
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

// Move
MyString::MyString(MyString &&source) : str(source.str)
{
    source.str = nullptr;
    fmt::println("Move Constructor Used");
}

MyString::~MyString() { delete[] str; }
// Display Method
//
//
MyString &MyString::operator=(const MyString &rhs)
{
    fmt::println("Copy Assignment");
    if (this == &rhs)
        return *this;

    delete[] str;

    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// Move Assignment
MyString &MyString::operator=(MyString &&rhs)
{
    // So Take the Pointer and make it point to value of
    // Data and the remove datas Pointer
    //
    fmt::println("Move Assignment");
    if (this == &rhs)
        return *this;

    delete[] str;
    str     = rhs.str;
    rhs.str = nullptr;
    return *this;
}

void MyString::display() const { fmt::println("{}: {}", str, get_length()); }

int MyString::get_length() const { return std::strlen(str); }

const char *MyString::get_str() const { return str; }
