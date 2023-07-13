#/*

clang++ -std=c++17 $0 -o $0.exe
exit $?

# */

#include <iostream>


int main () {
    int a = 42;

    std::cout << a << "\n";
    std::cout << &a << "\n";
    std::cout << (void*)a << "\n";
}
