#/*
clang++ -std=c++11 -Wall $0 -o $0.bin
exit $?
 */

#include <string>
#include <stdio.h>

class Base { public: virtual ~Base() {} };
class Derived : public Base { public: virtual ~Derived() {} };

int main() {
    Base *b = nullptr;
    Derived *d = dynamic_cast<Derived*>(b);

    printf("d=%lx\n", (unsigned long)d);
    return 0;
}



