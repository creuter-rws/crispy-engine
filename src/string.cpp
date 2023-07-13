
// It turns out += works with std::string.

#include <string>
#include <iostream>

int main() {
    std::string hw = "";

    hw += "Hello";
    hw += ", ";
    hw += "World!\n";

    std::cout << hw;

    return 0;
}
