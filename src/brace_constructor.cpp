#/*
clang++ -std=c++11 -Wall $0 -o $0.bin
exit $?
 */

#include <string>
#include <stdio.h>

class Foo {
    std::string s;
public:
    Foo(std::string ss) : s(ss) {}
    void print() const { printf("s=%s\n", s.c_str()); }
};


int main() {
    Foo x{"42"};
    x.print();

    return 1;
}


