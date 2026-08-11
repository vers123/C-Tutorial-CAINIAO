#include <stdio.h>

struct packed_struct {
    unsigned int f1:1;      // 1位的位域
    unsigned int f2:1;      // 1位的位域
    unsigned int f3:1;      // 1位的位域
    unsigned int f4:1;      // 1位的位域
    unsigned int type:4;    // 4位的位域
    unsigned int my_int:9;  // 9位的位域
};

int main() {
    struct packed_struct pack;

    pack.f1 = 1;
    pack.f2 = 0;
    pack.f3 = 1;
    pack.f4 = 0;
    pack.type = 7;
    pack.my_int = 255;

    printf("f1: %u\n", pack.f1);
    printf("f2: %u\n", pack.f2);
    printf("f3: %u\n", pack.f3);
    printf("f4: %u\n", pack.f4);
    printf("type: %u\n", pack.type);
    printf("my_int: %u\n", pack.my_int);
    
    return 0;
}