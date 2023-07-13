#include <stdio.h>

/*
  clang++ forvar.cpp -o forvar                  # Error
  clang++ -std=c++98 forvar.cpp -o forvar       # Error
  clang++ -xc -std=c99 forvar.cpp -o forvar     # Error

  clang++ -xc -std=c89 forvar.cpp -o forvar     # Success
 */


int main() {

    printf("start\n");
    
    for (int i = 0; i < 10; i++) {
        printf("i=%d\n", i);
    }

    //return 0;
    return i;       // Troublesome.
}

