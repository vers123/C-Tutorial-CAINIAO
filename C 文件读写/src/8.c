#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 错误示例：结构体包含指针成员
typedef struct {
    int id;
    char *name;   // 危险！fwrite 只保存指针值（地址），不保存字符串内容
} BadStudent;

// 正确示例：使用固定数组
typedef struct {
    int id;
    char name[100];  // 实际数据保存在结构体内，可以安全读写
} GoodStudent;

int main() {
    // 演示错误做法的后果
    BadStudent bs;
    bs.id = 1;
    bs.name = malloc(50);
    strcpy(bs.name, "RUNOOB");

    // 写入 BadStudent：此时 name 指针的地址被写入，字符串内容并未写入
    FILE *fp = fopen("./bad/bad.bin", "wb");
    fwrite(&bs, sizeof(BadStudent), 1, fp);
    fclose(fp);

    // 读回 BadStudent：name 指针值是之前 malloc 在另一个进程的地址，完全无效
    BadStudent loaded;
    fp = fopen("./bad/bad.bin", "rb");
    fread(&loaded, sizeof(BadStudent), 1, fp);
    fclose(fp);
    // loaded.name 是悬空指针，访问会导致未定义行为！

    free(bs.name);
    printf("演示完成，但 load 出来的 name 指针是无效的\n");
    return 0;
}