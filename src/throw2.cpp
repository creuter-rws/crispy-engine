#/*

#clang++ -Wall $0 -o $0.bin
clang++ -std=c++03 -Wall $0 -o $0.bin
exit $?

 */

#include <exception>
#include <iostream>

class oops1 : std::exception {
public:
    virtual const char *what() const throw() {
        return "oops1";
    }
};

class oops2 : std::exception {
    virtual const char *what() const throw() {
        return "oops2";
    }
};


class Kaboom {
public:
    Kaboom() {}
    ~Kaboom() {
        explode();
    }

    void explode(void);
        
};

void Kaboom::explode() { throw oops1(); }



int main() {
    Kaboom *a = new Kaboom();
    
    try {
        delete a;
    } catch(oops1& e) {
        std::cout << "throw " << e.what() << "\n";
    } catch(...) {
        std::cout << "caught mystery exception.\n";
    }

    return 0;
}
