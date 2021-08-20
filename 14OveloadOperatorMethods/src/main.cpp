#include <iostream>
#include "Mystring.h"

int main() {
    MyString a{"Cesc"};
    MyString b{"Cesc"};
    MyString c = a + " Ziomeczku";

    c.display();
    
    if (a == b)
        std::cout << a.GetStr() << " jest rowne " << b.GetStr() << std::endl;
    else
        std::cout << a.GetStr() << " nie jest rowne " << b.GetStr() << std::endl;

    MyString d{"DUPA"};
    MyString e = -d ;
    e.display();
    return 0;



}
