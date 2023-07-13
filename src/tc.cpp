
#include <string>
#include <vector>

// A target is now a set of sub-targets rather than a single platform.
// This is mainly to handle the case where we support both 32-bit and
// 64-bit x86 architectures: these run on the same machine but need to
// be kept separate in order to remain compatible with the user's
// plugins.

// Details related to one subtarget
struct SubTarget {
    const std::string exec_name;
    const std::string lib_name;

    SubTarget(const std::string& exec_name, std::string& lib_name) :
        exec_name(exec_name), lib_name(lib_name) {}
};

// Details related to a single target; it is now a bundle of sub-targets.
struct Target {
public:
    const std::string name;     // name; should match the common config names
    const std::vector<SubTarget> subs;

    //Target() : name("invalid-target") {}
    Target(const Target&) = default;
    
    Target(const std::string& name, std::vector<SubTarget>& subs)
        : name(name), subs(subs) {}
//    Target(const std::string& name, const std::initializer_list<SubTarget> subs_init)
//        : name(name), subs(subs_init) {}

    // Return a dummy Target; only used for unit tests.
    static Target null() {
        return Target("null-target", {});
    }
    
};

static Target& foo() {
    return Target("t1", {
            {"ix86-pc-linux-64", "lib64"},
            {"a", "b"}
        });
}


int main() {
    Target t = foo();
    return 0;
}
