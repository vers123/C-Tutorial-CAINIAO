#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024 // 每次读写 1KB, 可根据需要调整

// 高效文件复制函数
// 返回值: 0 表示成功, -1 表示失败
int copy_file(const char *src, const char *dst) {
    char buffer[BUFFER_SIZE];   // 中转缓冲区
    FILE *in = fopen(src, "rb");
    FILE *out = fopen(dst, "wb");

    // 检查两个文件是否都成功打开
    if (!in) {
        perror("源文件打开失败");
        return -1;
    }
    if (!out) {
        perror("目标文件打开失败");
        fclose(in);     // 关闭已打开的源文件
        return -1;
    }

    // 循环读取, 每次最多 BUFFER_SIZE 字节
    size_t n;
    while ((n = fread(buffer, 1, BUFFER_SIZE, in)) > 0) {
        // fwrite 的 size=1, count=n, 确保写入实际读取的字节数
        if (fwrite(buffer, 1, n, out) != n) {
            perror("写入失败");
            fclose(in);
            fclose(out);
            return -1;
        }
    }

    // 检查读取是否因错误而终止 (而非正常的 EOF)
    if (ferror(in)) {
        perror("读取错误");
        fclose(in);
        fclose(out);
        return -1;
    }

    fclose(in);
    fclose(out);
    printf("文件复制成功: %s -> %s\n", src, dst);
    return 0;
}

int main() {
    // 使用示例: 复制 runoob 测试文件
    copy_file("./runoob_input/runoob_input.bin", "./runoob_output/runoob_output.bin");
    return 0;
}