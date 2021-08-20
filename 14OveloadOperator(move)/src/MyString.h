#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class MyString
{
private:
    char *str; // pointer to a char[] that holds a C-style string
public:
    MyString();                 // No-args constructor
    MyString(const char *s);    //Overloaded constructor
    MyString(const MyString &source); //Copy constructor
    MyString(MyString &&source);      // Move constructor
    ~MyString();                // Destructor

    MyString &operator=(const MyString &rhs); //Copy assigment
    MyString &operator=(MyString &&rhs); //Move assigment

    void display() const;
    int GetLength() const;      // Getters
    const char *GetStr() const;
};

#endif // _MYSTRING_H_
