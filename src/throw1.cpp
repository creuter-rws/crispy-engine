#/*

#clang++-3.8 -std=c++03 -Wall $0 -o $0.bin
#clang++-3.8 -std=c++03 -Wall $0 -o $0.bin
#clang++ -std=c++03 -Wall $0 -o $0.bin
clang++ -Wall $0 -o $0.bin
exit $?

 */

#include <exception>
#include <iostream>

class oops1 : std::exception {
    virtual const char *what() const throw() {
        return "oops1";
    }
};

class oops2 : std::exception {
    virtual const char *what() const throw() {
        return "oops2";
    }
};



int main() {

    try {
        throw oops1();
    } catch(std::exception& e) {
        std::cout << "throw " << e.what() << "\n";
    }

    return 0;
}
