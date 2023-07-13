#/*

clang++ -std=c++17 $0 -o $0.exe
exit $?

# */

#include <iostream>

struct A {
    virtual void foo (int a = 1) {
        std::cout << "A" << a << "\n";
    }
};

struct B : A {
    virtual void foo (int a = 2) {
        std::cout << "B" << a << "\n";
    }
};

int main () {
    A *b = new B;
    b->foo();

    B *bb = new B;
    bb->foo();
}
