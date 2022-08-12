# Tooling

## Compiler

- Windows: g++, gdb, make via [Cygwin64](https://cygwin.com/install.html)
- Linux: g++, gdb, make via package manager (apt for Ubuntu for example)
- Mac: clang++, lldb, make via xcode-tools

## IDE: Visual Studio Code

- [Visual Studio Code](https://code.visualstudio.com/)

### VSCode Extensions

- Coding Tools Extension Pack (franneck94)
- C/C++ Extension Pack (franneck94)

## Clang Tools

We will use clang-format and clang-tidy.

- Clang-format: Formatter tool for source code
- Clang-tidy: Checks for issues in the code (similar to the compiler warnings)

## Steps from the video

0. Install all tools from the main course (including C/C++ Runner)
1. Copy settings below
2. Select folder in the blue status bar down below
3. F1 (Command Palette) > C Config Files (Minimal)
4. Paste the copied settings into the **settings.json** file

### Extra settings (for local .vscode/settings.json file)

```json
  "C_Cpp_Runner.warnings": [
    "-Wall",
    "-Wextra",
    "-Wpedantic",
    "-Wshadow",
    "-Wconversion",
    "-Woverflow",
    "-Wformat=2",
    "-Wsign-conversion",
    "-Wstrict-overflow=1",
    "-Wnull-dereference",
  ],
  "C_Cpp_Runner.compilerArgs": [],
  "C_Cpp_Runner.includePaths": [],
  "C_Cpp_Runner.linkerArgs": [
      "-lm"
  ],
  "C_Cpp_Runner.cStandard": "c99",
  "C_Cpp_Runner.cppStandard": "c++17",
  "C_Cpp_Runner.excludeSearch": [
      "**/scripts/"
  ],
  "C_Cpp_Runner.enableWarnings": true,
  "C_Cpp_Runner.warningsAsError": false,
  "Workspace_Formatter.includePattern": [
    "*.h",
    "*.c",
    "**/*.h",
    "**/*.c"
  ],
```
