# Compiler and flags
CXX = g++
CXXFLAGS = -g --std=c++23 -I../include -L../lib #All your compilation flags are stored here, making it easier to manage and extend.

# Libraries
LIBS = -lglfw3dll -lopengl32 # Contains both -lglfw3dll for GLFW and -lopengl32 for OpenGL on Windows.

# Source files
SRCS = ../src/main.cpp ../src/glad.c #Lists both main.cpp and glad.c, which are necessary for compiling your project.

# Target executable
TARGET = main #This target builds the main.exe.

# Build target
all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRCS) $(LIBS) -o $(TARGET)

# Clean target
clean:
	del $(TARGET).exe
