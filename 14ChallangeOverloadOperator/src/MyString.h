#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class MyString
{
private:
    char *str; // pointer to a char[] that holds a C-style string
    friend MyString operator+(const MyString &lhs, const MyString &rhs);
    friend MyString &operator+=(MyString &lhs, const MyString &&rhs);
    friend bool operator!=(const MyString &lhs, const MyString &rhs);
    friend bool operator>(const MyString &lhs, const MyString &rhs);
    friend bool operator<(const MyString &lhs, const MyString &rhs);
    friend MyString operator*(const MyString &lhs, const int Multiply);
    friend MyString &operator*=(MyString &lhs, const int Multiply);
    friend std::ostream &operator<<(std::ostream &os, const MyString &rhs); 
public:
    MyString();                 // No-args constructor
    MyString(const char *s);    //Overloaded constructor
    MyString(const MyString &source); //Copy constructor
    MyString(MyString &&source);      // Move constructor
    ~MyString();                // Destructor

    MyString &operator=(const MyString &rhs); //Copy assigment
    MyString &operator=(MyString &&rhs); //Move assigment
    MyString operator-() const;
    MyString &operator++();
    bool operator==(const MyString &rhs) const;

    void display() const;
    int GetLength() const;      // Getters
    const char *GetStr() const;
};

#endif // _MYSTRING_H_
