# **acmicpc<area>.net**

![profile](profile.png)

Solutions for problems I solved in [Baekjoon Online Judge](https://www.acmicpc.net/), a Korean website for practicing algorithms.


## **Table of Contents**

- [**Description**](#description)
    - [Notes](#notes)
    - [Problem Index](#problem-index)
- [**Templates**](#templates)
    - [What is in template directory?](#what-is-in-template-directory)
    - [How to create new directories?](#how-to-create-new-directories)
    - [Linux Templates](#linux-templates)


## **Description**

### Notes

The codes are personal solutions for problems in Baekjoon Online Judge. I sorted them in order of [단계별로 풀어보기](https://www.acmicpc.net/step), though some of the problems are labeled arbitrarily. I will also add more problems not in 단계별로 풀어보기 in this fashion as I solve them.

### Problem Index

Each problem directories has a name in numbers (e.g. `03-loop/2741`). It is same as a problem index in Baekjoon Online Judge. You can check out the original problem such as [acmicpc.net/problem/2741](https://www.acmicpc.net/problem/2741).

## **Templates**

### What is in template directory?

There are `main.cpp` and `template_vs19.zip` in `template/` . `main.cpp` is a template source code where frequently used headers and variables are declared. For instance,
- C++ headers such as `<iostream>` to STL containers are included. 
    - Some redundant headers are for Visual Studio support.
- `setup` function speeds up `cin` and `cout` for time limits.
- Variables such as `int arr[]` , `unsigned long long t, m, n` are pre-defined.

`template_vs19.zip` is a template for problem directory which is copied to create new problem directory. Its usage is described below.

### How to create new directories?

> **Disclaimer**<br>
> This method only works in Windows with [Visual Studio 2019 installed](https://visualstudio.microsoft.com/ko/downloads/).

I use Visual Studio 2019 for compile and debugging, and Visual Studio Code for editing. There is `.vscode` directory in `template_vs19.zip` file which helps vscode integration.

When creating new directories to solve new problems, first extract `template_vs19.zip` file to new directory. Then go to new directory **with Developer Powershell for VS 2019**. Open with code,

```
code .
```

then press `F5` to build. Note that you must use Developer Powershell for VS 2019 otherwise you would fail with the builds.

### Linux Templates

Recently, I added templates for `clang++` as I begin to use Ubuntu Desktop. They are in `template_lin` directory and the usage is same. 

However, there are some prerequisites. First, you need to install `clang`, `lld`, `lldb` and Libc package for clang. 

```bash
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key|sudo apt-key add -
sudo apt-get install clang-12 lldb-12 lld-12
sudo apt-get install libc++-12-dev libc++abi-12-dev
```

Then, install [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb) plugin for VSCode. This way, you will be able to build and debug easily with STL container supports.