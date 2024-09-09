cmake_minimum_required(VERSION 3.10)
project(OpenGL_Project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add include directories
include_directories(include)

# Add the source files
set(SOURCES
    src/glad.c
    src/main.cpp
)

# Add the executable
add_executable(main ${SOURCES})

# Link libraries
target_link_libraries(main PRIVATE ${CMAKE_SOURCE_DIR}/lib/libglfw3dll.a)

# Define where to find the GLFW library (adjust the path if needed)
link_directories(${CMAKE_SOURCE_DIR}/lib)
