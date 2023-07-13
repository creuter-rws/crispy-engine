
#include <iostream>
#include <type_traits>
 

struct Foo
{
    int foo;
    void (&bar)();  // This should not result in the structure being considered other than the POD.  But it does.  
    // MISRA.MEMB.NOT_PRIVATE is generated when it should not be.  
};
 
int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_pod<Foo>::value << '\n';
}
