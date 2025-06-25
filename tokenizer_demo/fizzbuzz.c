#include <stdio.h>
int main() {
    for(int i = 0; i < 100; ++i) {
        if(!(i % 3)) printf("Fizz");
        if(!(i % 5)) printf("Buzz");
        printf("\n");
    }
    return 0;
}