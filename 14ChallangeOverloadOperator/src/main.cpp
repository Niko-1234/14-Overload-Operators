#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    MyString a{"miko"};
    MyString b{"miko"};
    cout << "MyString a = " << a.GetStr() << endl;
    cout << "MyString b = " << b.GetStr() << endl;
    cout << "Comparison a to b, 1: equal, 2: negation" << endl;
    cout << (a==b) << endl;
    cout << (a!=b) << endl;
    cout << "Comparison a to b, 1: equal, 2: negation, 3: a>b, 4: a<b" << endl;
    b = "kamil";

    cout << (a==b) << endl;
    cout << (a!=b) << endl;
    cout << (a>b) << endl;
    cout << (a<b) << endl;

    MyString c{"DUPA"};
    cout << c << endl;
    c = -c;
    cout << c << endl;
    MyString d;
    d = c + " i chuj";
    cout << d << endl;
    c += " i cipa ";

    c = "aaa|";
    d = c*3;
    cout << d << endl;
    d = "bbb|";
    d *= 4;
    cout << d << endl;

    a = "Miko";

    MyString result;
    result = ++a;
    cout << a;

    return 0;
}
