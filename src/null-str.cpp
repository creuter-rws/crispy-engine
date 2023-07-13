
#include <string>
#include <stdio.h>

int main() {
    char *zip = nullptr;

    std::string huh = zip;
    printf("huh=[%s]\n", huh.c_str());

    return 0;
}
       
    
