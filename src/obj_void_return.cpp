#/*

clang++ -std=c++17 -Wall $0 -o $0.exe && echo "Running:" && echo && ./$0.exe
exit $?

# */

#include <string>
#include <iostream>

class Foo {
private:
    int x;
public:
    Foo() : x(42) {
        std::cout << "Called Foo::Foo()\n";
    }
};


Foo newfoo() {
    if (false) {
        return Foo();
    }        
};



int main() {
    Foo ff = newfoo();
    return 0;
}
    


    
        
