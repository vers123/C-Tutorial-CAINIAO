#include <stdio.h>

int main() {
    int buffer[100];
    FILE *fp = fopen("./data/data.bin", "rb");
    if (fp == NULL) {
        perror("文件打开失败");
        return 1;
    }

    // 尝试读取 100 个整数
    size_t count = fread(buffer, sizeof(int), 100, fp);

    if (count < 100) {
        // 区分 EOF 和错误
        if (feof(fp)) {
            printf("已到达文件末尾, 实际读取 %zu 个元素\n", count);
            // 此时可以继续处理已读取的数据
        } else if (ferror(fp)) {
            perror("读取过程中发生错误");
            fclose(fp);
            return 1;
        }
    } else {
        printf("成功读取全部 %zu 个元素\n", count);
    }

    fclose(fp);
    return 0;
}