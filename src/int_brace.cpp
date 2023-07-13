#/*
clang++ -std=c++11 -Wall $0 -o $0.bin
exit $?
 */

#include <iostream>

int main() {
    int v{};    // what does this do?

    std::cout << v << std::endl;
    return 0;
}
