#include <stdio.h>

// 问题示例：默认对齐下，char 后会有 3 字节填充
typedef struct {
    char c;      // 占 1 字节，但后面会有填充
    int i;       // 4 字节对齐，实际从偏移 4 开始
} Mixed;

// 解决方法一：使用 pragma pack 强制紧凑对齐
#pragma pack(push, 1)  // 保存当前对齐设置，设为 1 字节对齐
typedef struct {
    char c;      // 偏移 0，占 1 字节
    int i;       // 偏移 1，占 4 字节（无填充）
} PackedMixed;
#pragma pack(pop)      // 恢复之前的对齐设置

// 解决方法二：手动逐个序列化成员（最安全的方式）
// 这种方法不依赖编译器对齐，跨平台兼容性最好

int main() {
    // 打印两种结构体的大小差异
    printf("默认对齐 Mixed 大小: %zu 字节\n", sizeof(Mixed));       // 通常为 8
    printf("紧凑对齐 PackedMixed 大小: %zu 字节\n", sizeof(PackedMixed)); // 为 5
    return 0;
}