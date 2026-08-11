#include <stdio.h>

struct example1 {
    int a : 4;
    int b : 5;
    int c : 7;
};

int main() {
    struct example1 ex1;

    printf("Size of example1: %lu bytes\n", sizeof(ex1));
    
    return 0;
}