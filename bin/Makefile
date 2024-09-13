# Compiler and flags
CXX = g++
CXXFLAGS = -g --std=c++23 -I../include -I../header -L../lib

# Libraries
LIBS = -lglfw3dll -lopengl32 # For GLFW and OpenGL on Windows.

# Source files
SRCS = $(wildcard ../src/*.cpp ../src/*.c) # Automatically includes all .cpp and .c files from src folder

# Target executable
TARGET = main # This target builds the main.exe.

# Build target
all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRCS) $(LIBS) -o $(TARGET)

# Clean target
clean:
	del $(TARGET).exe
