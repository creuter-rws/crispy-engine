
#include <cstdio>

class Bar {
protected:
    virtual void blort() = 0;

public:
    template <class T>
    static void go() {
        T d;
        Bar *t = static_cast<Bar*>(&d);
        t->blort();
    }// go
};

class Dodo : public Bar {
private:
    void blort() override { printf("blort!!!!\n"); }
};

int main() {
    Bar::go<Dodo>();
    return 0;
}
