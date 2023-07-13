#/*
    g++ -std=c++14 $0 -o $0.exe
    exit $?
 */


#include <memory>

struct Foo {
    int a;
    int b;
};


int main() {
    std::unique_ptr<Foo> fp(nullptr); //std::make_unique<Foo>();
    printf("%lx\n", &fp->b);

    return 0;
}
