#/*

clang++ -std=c++17 -Wall $0 -o $0.exe && echo "Running:" && echo && ./$0.exe
exit $?

# */

#include <string>
#include <iostream>

int main() {
    std::string foo = nullptr;

    std::cout << foo;

    return 0;
}
    


    
        
