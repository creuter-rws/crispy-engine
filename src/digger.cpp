#/*
clang++ -std=c++17 -Wall $0 -o $0.bin
exit $?
 */

//
// dabbling with a method to follow chains of objects where pointer conversions may fail.
//


#include <vector>
#include <functional>


class thing {
protected:
    std::vector<thing*> all_things;

public:
    virtual ~thing() {}
    
    virtual void add_thing(thing* t) { all_things.push_back(t); }

    virtual thing* get_thing(size_t idx) {
        return idx < all_things.size() ? all_things[idx] : nullptr;
    }
};

class good_thing : public thing {
};

class better_thing : public good_thing {
};

class bad_thing : public thing {
public:
    virtual thing* first() { return get_thing(0); }
};

class worse_thing: public bad_thing {
};

class meh_thing : public thing {
};


template<typename T>
class NullBox {
private:
    T* it;

public:
    NullBox(T* it) : it(it) {}

    template <typename Src>
    NullBox<Src>(Src* it) : it(dynamic_cast<T*>(it)) {}
    
    NullBox() : it(nullptr) {}

    T* get() const { return it; }
    
    template<typename Target>
    NullBox<Target> then(std::function<Target*(T*)> fn) {
        if (!it) { return NullBox<Target>(); }
        return NullBox<Target>( fn(it) );
    }
};




int main() {
    thing *t = new thing;

    t->add_thing(new good_thing);
    t->add_thing(new bad_thing);

    t->get_thing(1)->add_thing(new meh_thing);

//    auto *t1 = t->get_thing(3)->first();

    auto *t1 = NullBox(t)
        .then<bad_thing>( [](auto *t) -> bad_thing { return t->get_thing(1); } )
        .then<meh_thing>( [](auto *t) -> meh_thing { return t->first(); } )
        .get();

    
    return 0;
}
