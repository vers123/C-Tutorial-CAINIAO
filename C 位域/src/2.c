struct 
{
    unsigned int age : 3;
} Age;

struct bs {
    int a:8;
    int b:2;
    int c:6;
}data;

struct packed_struct {
    unsigned int f1:1;
    unsigned int f2:1;
    unsigned int f3:1;
    unsigned int f4:1;
    unsigned int type:4;
    unsigned int my_int:9;
} pack;