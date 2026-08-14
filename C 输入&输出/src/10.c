#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("../src/10/example.txt", "w");
    if (file != NULL) {
        fprintf(file, "Hello, World!\n");
        fclose(file);
    }

    char buffer[100];
    file = fopen("../src/10/example.txt", "r");
    if (file != NULL) {
        fgets(buffer, sizeof(buffer), file);    // 读取整行
        printf("Read from file: %s", buffer);   // fgets 会保留换行符
        fclose(file);
    }
    return 0;
}