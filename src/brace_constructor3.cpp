#/*
clang++ -std=c++11 -Wall $0 -o $0.bin
exit $?
*/

#include <string>

class Foo {
    std::string s;
public:
    Foo(const std::string &ss) : s(ss) {}
    const char *sss() const { return s.c_str(); }
};

class Bar {
public:
    int zzz;

    void blort() { }
private:
    Foo x{"42"}, y{"123"};
    Foo zz_z{"39"};
};


int main() {
    Foo x{"42"}, y{"999"};
    return 1;
}


