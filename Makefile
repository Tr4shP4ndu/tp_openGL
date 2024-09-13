# Compiler and flags
CXX = g++
CXXFLAGS = -g --std=c++23 -I./include -I./header -L./lib

# Libraries
LIBS = -lglfw3dll -lopengl32 # For GLFW and OpenGL on Windows.

# Source files
SRCS = $(wildcard ./src/*.cpp ./src/*.c) # Automatically includes all .cpp and .c files from src folder

# OUT executable
OUT = bin/main # This OUT builds the main.exe.

# Build OUT
all: $(OUT)

$(OUT): out_resources
	$(CXX) $(CXXFLAGS) $(SRCS) $(LIBS) -o $(OUT)

out_resources:
	Copy-Item -Path "resources" -Destination "bin" -Recurse

# Clean OUT
clean:
	del $(OUT).exe
