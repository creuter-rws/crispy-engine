#/*

clang++ -std=c++17 -Wall $0 -o $0.exe && echo "Running:" && echo && ./$0.exe
exit $?

# */

#include <string>
#include <iostream>

class Thing {
    std::string it;
public:
    Thing() {  std::cout << "new Thing()\n"; }
    virtual ~Thing() { std::cout << "Thing::Kaboom\n"; }
    virtual void foo() {}
};


class BetterThing : public Thing {
public:
    BetterThing() {  std::cout << "new BetterThing()\n"; }
    ~BetterThing() { std::cout << "BetterThing::Kaboom\n"; }
};


int main() {
    BetterThing *bt = new BetterThing();

    delete bt;

    return 0;
}
    


    
        
