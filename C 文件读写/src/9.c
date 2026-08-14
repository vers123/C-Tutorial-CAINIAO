#include <stdio.h>

int main() {
    FILE *fp = fopen("./critical/critical.bin", "wb");
    if (fp == NULL) {
        perror("文件打开失败");
        return 1;
    }

    int data[] = {1, 2, 3, 4, 5};
    fwrite(data, sizeof(int), 5, fp);

    // 方法一：显式刷新缓冲区，数据立即写入磁盘
    fflush(fp);
    printf("使用 fflush 强制刷新到磁盘\n");

    // 方法二：关闭文件时自动刷新（推荐）
    // fclose 内部会自动调用 fflush
    fclose(fp);
    printf("fclose 也会自动刷新缓冲区\n");

    return 0;
}