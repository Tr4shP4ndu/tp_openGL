#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Callback function for handling framebuffer size changes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // Update the viewport dimensions to match the new framebuffer size
    glViewport(0, 0, width, height);
} 

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() 
{
    // Initialize GLFW
    glfwInit();

    // Configure GLFW to use OpenGL version 3.3 and core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

    // Load OpenGL function pointers using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set the framebuffer size callback function
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

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
