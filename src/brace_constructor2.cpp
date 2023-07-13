#/*
clang++ -std=c++11 -Wall $0 -o $0.bin
exit $?
 */


class Foo {
    const char * s;
public:
    Foo(const char * ss) : s(ss) {}
    const char *sss() const { return s; }
};

class Bar {
public:
    Foo x{"42"};
};


int main() {
    Foo x{"42"}, y{"999"};
    return 1;
}


