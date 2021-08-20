#include <cstring>
#include <string>
#include <iostream>
#include "MyString.h"

//No-args constructor
MyString::MyString()
    : str{nullptr}
    {
        str = new char[1];
        *str = '\0';
    }

//Overloaded constructor
MyString::MyString(const char *s)
    :str {nullptr} // initialize pointer str
    {
        if (s == nullptr)
        {
            str = new char[1];
            *str = '\0';
        } 
        else
        {
            str = new char[std::strlen(s) + 1];
            std::strcpy(str, s);
        } 
    // std::cout << "Overloaded constructor used" << std::endl;     
    }

//Copy constructor
MyString::MyString(const MyString &source)
    :str{nullptr}
    {
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
        // std::cout << "Copy constructor used" << std::endl;
    }

//Move constructor
MyString::MyString(MyString &&source)
:str(source.str) //Point to the same place at heap as the source do
{
    source.str = nullptr; //initialize source pointer
    // std::cout << "Move constructor used" << std::endl;
}
// Destructor
MyString::~MyString(){
    // if (str == nullptr){
    //     std::cout << "Calling destructor for: nullptr" << std::endl;
    // }else{
    //     std::cout << "Calling destructor for: " << str << std::endl;
    // }
    delete [] str;
}

//Copy assigment
MyString &MyString::operator=(const MyString &rhs)
{
    // std::cout << "Copy assigment" << std::endl;
    if (this == &rhs)
        return *this;
    delete [] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str,rhs.str);
    return *this;
}

//Move assigment
MyString &MyString::operator=(MyString &&rhs)
{
    // std::cout << "Move assigment" << std::endl;
    if (this == &rhs)
        return *this;
    delete [] this->str; //cleaning pointer which was initialized in constructor
    str = rhs.str;       //move rhs pointer to this obj pointer
    rhs.str = nullptr;   //initialize source pointer
    return *this;
}

//Equality
bool MyString::operator==(const MyString &rhs) const
{
    return (std::strcmp(str, rhs.str) == 0); 
}

//Make lowercase
MyString MyString::operator-() const
{
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i = 0; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    // for (char x : buff)
    //     x = std::tolower(x);
    MyString temp {buff};
    delete [] buff;
    return temp;
}

//Make CAPITAL
MyString &MyString::operator++()
{
    for (size_t i = 0; i < std::strlen(str); i++)
        str[i] = std::toupper(str[i]);
    return *this;
}

//Conectate: no-member method
MyString operator+(const MyString &lhs, const MyString &rhs)
{
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    MyString temp{buff};
    delete [] buff;
    return temp;
}

//Conectate: no-member method +=
MyString &operator+=(MyString &lhs, const MyString &&rhs)
{
    lhs = lhs + rhs;
    return lhs;
}
//Negation: no-member function
bool operator!=(const MyString &lhs, const MyString &rhs)
{
    return !(std::strcmp(lhs.str,rhs.str) == 0);
}

//Comparison >
bool operator>(const MyString &lhs, const MyString &rhs)
{
    int MaxCount {0};
    if (strlen(lhs.str) > strlen(rhs.str))
        MaxCount = strlen(lhs.str);
    else
        MaxCount = strlen(rhs.str);

    return (strncmp(lhs.str,rhs.str,MaxCount) > 0);
}

//Comparison <
bool operator<(const MyString &lhs, const MyString &rhs)
{
    int MaxCount {0};
    if (strlen(lhs.str) > strlen(rhs.str))
        MaxCount = strlen(lhs.str);
    else
        MaxCount = strlen(rhs.str);

    return (strncmp(lhs.str,rhs.str,MaxCount) < 0);
}

//Output MyString
std::ostream &operator<<(std::ostream &os, const MyString &rhs) 
{
    os << rhs.GetStr();
    return os;
}
//Multiplayer
MyString operator*(const MyString &lhs, const int Multiply)
{
    char *buff = new char [strlen(lhs.str) * Multiply + 1];
    strcpy(buff,lhs.str);
    for (size_t i  = 0; i < Multiply - 1; ++i)
        strcat(buff,lhs.str);
    MyString temp{buff};
    delete [] buff;
    return temp; 
}

//Multiplayer *=
MyString &operator*=(MyString &lhs, const int Multiply)
{
    return lhs = lhs * Multiply;
}


void MyString::display() const 
{
    std::cout << str << " : " << GetLength() << std::endl;
}

int MyString::GetLength() const {return std::strlen(str);}

const char *MyString::GetStr() const {return str;}