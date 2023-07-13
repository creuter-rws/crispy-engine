#/*
clang++ -std=c++11 -Wall $0 -o $0.bin
exit $?
 */

#include <cstdio>

class Foo {
    int x = 42;
    int xx = 99;
public:
    int *getX() { return &x; }
    const int *getX() const { return &xx; }
};

int main() {
    Foo f1;
    const Foo f2;

    printf("%d %d\n", *(f1.getX()), *(f2.getX()));
    
    return 1;
}


