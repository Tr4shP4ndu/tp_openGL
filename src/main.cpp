#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

// Function to handle window resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
    glViewport(0, 0, width, height);
}

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// ------------------------------

// Function to process input (close window if ESC is pressed)
void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// ------------------------------


// Vertex Shader source code (runs on GPU, transforms vertex positions)
const char* vertexShaderSource =    "#version 330 core\n"
                                    "layout (location = 0) in vec3 aPos;\n"
                                    "void main()\n"
                                    "{\n"
                                    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                    "}\0";

// Fragment Shader source code (runs on GPU, controls pixel color)
const char* fragmentShaderSource =  "#version 330 core\n"
                                    "out vec4 FragColor;\n"
                                    "void main()\n"
                                    "{\n"
                                    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                    "}\n\0";
// ------------------------------

// Get ESC Key when press to close the window
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


int main() 
{
    // glfw: initialize and configure
    glfwInit();

    // Configure GLFW to use OpenGL version 3.3 and core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // ------------------------------

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL) 
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    // Set the framebuffer size callback function
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // ------------------------------

    // Load All OpenGL function pointers using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    // ------------------------------



    // Define the vertices for a triangle - set up vertex data (and buffer(s)) and configure vertex attributes
    float vertices[] = {
         0.5f,  0.5f, 0.0f,  // Top right
         0.5f, -0.5f, 0.0f,  // Bottom right
        -0.5f, -0.5f, 0.0f,  // Bottom left
        -0.5f,  0.5f, 0.0f   // Top left
    };

    // Define indices to draw the triangle using two triangles
    unsigned int indices[] = { // note that we start from 0!
        0, 1, 3,   // First triangle
        1, 2, 3    // Second triangle
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO); 
    // ------------------------------




    // Main loop
    while (!glfwWindowShouldClose(window)) 
    {
        // Poll for and process events
        glfwPollEvents();

        processInput(window);
 
        // Clear the screen with a blue washed color
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
 
        // Swap front and back buffers
        glfwSwapBuffers(window);
    }
 
    // Terminate GLFW and clean up resources
    glfwTerminate();
    return 0;
}
