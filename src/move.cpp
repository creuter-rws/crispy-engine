
#include <cstddef>
#include <utility>

class Thing {
    char *thing = nullptr;
    unsigned id;
    static unsigned count = 0;

public:
    Thing() : id(count++) {}
    ~Thing() {
        if (thing) {
            delete thing;
            msg("thing set on delete");
        }
    }

private:
    void msg(const char *txt) {
        std::cout << "ID:" << id << "; " << msg << "\n";
    }

public:
    void set() {
        msg("setting thing");
        delete thing;
        thing = new[8];
    }
};





    
