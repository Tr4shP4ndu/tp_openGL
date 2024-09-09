# Guide to Installing C++ & OpenGL

## Table of Contents

- [Guide to Installing C++ \& OpenGL](#guide-to-installing-c--opengl)
  - [Table of Contents](#table-of-contents)
  - [Installation](#installation)
    - [Windows](#windows)
    - [macOS](#macos)
    - [Linux](#linux)
  - [Setting Up a C++ IDE](#setting-up-a-c-ide)
    - [Visual Studio Code](#visual-studio-code)
  - [Setup GLAD \& GLFW](#setup-glad--glfw)
    - [Glad](#glad)
    - [GLFW](#glfw)
  - [VS Code Setup](#vs-code-setup)
  - [Makefile](#makefile)

## Installation

### Windows

1. **Install MinGW**:
   - Go to the [MinGW-w64 download page](https://www.mingw-w64.org/download/) or Download Using [MinGW-w64 download page](https://github.com/msys2/msys2-installer/releases/download/2023-05-26/msys2-x86_64-20230526.exe).
   - Download and install the appropriate version.
   - Run the terminal MSYS2 or type MINGW.
   - In that terminal run this command `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain` and enter.
     - Accept by pressing Y.
   - After updating MSYS2 we then paste this command `pacman -S mingw-w64-ucrt-x86_64-gcc`
     - This installs the gcc compilers for your projects.
     - To view after installing just type `gcc --version`.
   - Add the path of your MinGW-w64 bin folder to the Windows PATH environment variable.
     - Press Windows Key and type Edit Environment Variables.
       - Either in User or System, select PATH and Edit.
     - Make New and add the path for your MINGW, default is: `C:\msys64\ucrt64\bin`

2. **Verify Installation**:
   - Open Command Prompt and type:
     ```bash
     gcc --version
     g++ --version
     gdb --version
     ```
   - You should see the installed version of `g++`.


### macOS

1. **Install Xcode Command Line Tools**:
   - Open Terminal and type:
     ```bash
     xcode-select --install
     ```

2. **Verify Installation**:
   - In Terminal, type:
     ```bash
     g++ --version
     ```
   - The installed version of `g++` should be displayed.

### Linux

1. **Install GCC**:
   - For Debian/Ubuntu-based systems:
     ```bash
     sudo apt update
     sudo apt install build-essential
     ```

   - For Red Hat/CentOS-based systems:
     ```bash
     sudo yum groupinstall 'Development Tools'
     ```

2. **Verify Installation**:
   - In Terminal, type:
     ```bash
     g++ --version
     ```

## Setting Up a C++ IDE

### Visual Studio Code

[Follow the Guide in VSCode to Setup GCC in your IDE](https://code.visualstudio.com/docs/languages/cpp)
1. Recommend to install these Extensions:
   - Code Runner
   - C/C++
2. Then make your first program:
   1. When running the first time `Run C/C++ File` select the debug **C/C++:g++.exe**
   2. It will become default and will add to your **task.json** and **settings.json**


## Setup GLAD & GLFW

### Glad

- First let's download GLAD from the website: [GLAD](https://glad.dav1d.de/)
  - Language: C/C++ 
  - Specification: OpenGL
  - API:
    - gl: Version 3.3
  - Profile: Core
  - Generate
  - Download ONLY glad.
- Bring all the files from glad.zip to your "Working Project"

### GLFW

- First let's download GLAD from the website: [GLFW](https://www.glfw.org/download.html)
- Download the Pre-Compiled Binaries from your OS System
- Inside the zip folder go towards glfw-[version].bin.[OS] then include and copy the GLFW to the include folder from your "Working Project" that we gradded from GLAD
- Now go back and find the folder called "lib-mingw-w64"
  - Create a new folder inside of the "Working Project" called "lib" and drag a file called libglfw3dll.a into it.
  - create another folder called "bin" in your "Working Project" and drag the file called "glffw3.dll" to that folder.

## VS Code Setup

Our main.cpp file is going to be located in the src folder where it contains the file glad.c.

In the same repo, we are providing you a "template" for setting up your .vscode to setup C++ and OpenGL


## Makefile

The Makefile is going to be located in the bin folder where we will be compiling our program and run it.

Remember to change the settings inside to contain the correct path for the libraries and main.cpp


