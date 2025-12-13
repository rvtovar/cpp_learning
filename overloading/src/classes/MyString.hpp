#pragma once
class MyString
{
  private:
    char *str;

  public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &source); // Copy Constructor

    MyString(MyString &&source); // Move Constructor

    ~MyString();

    MyString &operator=(const MyString &rhs); // COpy Assignment
                                              // Move Assignment
    MyString   &operator=(MyString &&rhs);    // Move Assignment
    void        display() const;
    int         get_length() const;
    const char *get_str() const;
};
