# Tutorial C by CAINIAO Web

[English](#english) | [中文-简体](#中文)

---

## English

> This is a C programming tutorial project based on the [CAINIAO](https://www.runoob.com) website examples.

### Project Structure
```text
project/
└─ C_ProjectName/            # Root folder for your C project
    ├── build/               # Compiled executable files (.exe on Windows)
    └── src/                 # Source code files (.c)
```

- `src/`: Place all your `.c` source files here.
- `build/`: Compiled binaries will be output here (keeps source and binaries separate).

### Prerequisites
- Install a C compiler (e.g., **GCC** from MinGW on Windows, or `gcc` on Linux/macOS).
- Verify installation:
  ```bash
  gcc --version
  ```

### Quick Start

1. **Clone the repository** (if applicable)
   ```bash
   git clone <your-repo-url>
   cd <repo-folder>
   ```

2. **Create the project folder structure**
   ```bash
   mkdir C_ProjectName        # Replace 'ProjectName' with your actual project name
   cd C_ProjectName
   mkdir src build
   ```

3. **Write your C code**  
   Create a source file, e.g., `hello.c`, inside the `src/` folder with your code.

4. **Compile the program**  
   Use GCC to compile the source and output the executable to the `build/` folder:
   ```bash
   gcc ./src/hello.c -o ./build/hello
   ```
   - `-o` specifies the output file name (no extension needed on Linux/macOS; on Windows, it will create `hello.exe`).

5. **Run the compiled program**
   ```bash
   # On Linux/macOS:
   ./build/hello

   # On Windows (Command Prompt):
   .\build\hello.exe
   ```

### Example Session
```bash
$ mkdir C_MyProject
$ cd C_MyProject
$ mkdir src build
$ echo '#include <stdio.h>\nint main() { printf("Hello, C!\\n"); return 0; }' > src/main.c
$ gcc ./src/main.c -o ./build/main
$ ./build/main
Hello, C!
```

---

## 中文

> 这是基于[菜鸟教程](https://www.runoob.com) C 语言学习内容的示例项目模板。

### 项目结构
```text
project/
└─ C_项目名称/               # C 项目的根目录
    ├── build/               # 存放编译后的可执行文件（Windows 下为 .exe）
    └── src/                 # 存放源代码文件（.c）
```

- `src/`：存放所有 `.c` 源文件。
- `build/`：编译输出目录，用于分离源码和编译产物。

### 环境准备
- 安装 C 编译器（如 Windows 的 MinGW 中的 **GCC**，或 Linux/macOS 自带的 `gcc`）。
- 验证安装：
  ```bash
  gcc --version
  ```

### 快速开始

1. **克隆仓库**（如有）
   ```bash
   git clone <你的仓库地址>
   cd <仓库文件夹>
   ```

2. **创建项目文件夹结构**
   ```bash
   mkdir C_项目名称            # 将 '项目名称' 替换为实际名称
   cd C_项目名称
   mkdir src build
   ```

3. **编写 C 代码**  
   在 `src/` 文件夹中创建源文件，例如 `hello.c`，写入你的代码。

4. **编译程序**  
   使用 GCC 编译，并将可执行文件输出到 `build/` 文件夹：
   ```bash
   gcc ./src/hello.c -o ./build/hello
   ```
   - `-o` 指定输出文件名（Linux/macOS 下无后缀；Windows 下会生成 `hello.exe`）。

5. **运行编译后的程序**
   ```bash
   # Linux/macOS:
   ./build/hello

   # Windows（命令提示符）：
   .\build\hello.exe
   ```

### 示例操作
```bash
$ mkdir C_我的项目
$ cd C_我的项目
$ mkdir src build
$ echo '#include <stdio.h>\nint main() { printf("Hello, C!\\n"); return 0; }' > src/main.c
$ gcc ./src/main.c -o ./build/main
$ ./build/main
Hello, C!
```

---

### Notes / 注意事项
- Always ensure your source files have the `.c` extension.
- The `build/` folder can be ignored by version control (add to `.gitignore`) to keep the repository clean.
- 确保源文件扩展名为 `.c`。
- 建议将 `build/` 文件夹加入 `.gitignore`，避免将编译文件提交到版本库。
