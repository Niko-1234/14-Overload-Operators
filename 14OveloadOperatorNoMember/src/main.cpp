#include <iostream>
#include "Mystring.h"

int main() {
    MyString a{"Czesc"};
    MyString c = "Ziomeczku " + a;
    c.display();
    return 0;
}
