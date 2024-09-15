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
void processInput(GLFWwindow *window) 
{
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


    // build and compile our shader program
    // ------------------------------------
    // vertex shader, instead of using unsigned int we use GLuint
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // Attach Vertex Shader source to the Vertex Shader Object
    glCompileShader(vertexShader); // Compile the Vertex Shader into machine code
    
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); // Create Fragment Shader Object and get its reference
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL); // Attach Fragment Shader source to the Fragment Shader Object
    glCompileShader(fragmentShader); // Compile the Vertex Shader into machine code
    
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // link shaders
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader); // Attach the Vertex and Fragment Shaders to the Shader Program
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram); // Wrap-up/Link all the shaders together into the Shader Program
    
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Define the vertices for a triangle - set up vertex data (and buffer(s)) and configure vertex attributes
    GLfloat vertices[] =
                        {
                          -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
                          0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
                          0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
                        };


    GLuint VBO, VAO; // Create reference containers for the Vartex Array Object and the Vertex Buffer Object
    // Generate the VAO and VBO with only 1 object each
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO); // Bind the VBO specifying it's a GL_ARRAY_BUFFER
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Introduce the vertices into the VBO

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); // Configure the Vertex Attribute so that OpenGL knows how to read the VBO
    glEnableVertexAttribArray(0); // Enable the Vertex Attribute so that OpenGL knows to use it

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 


    // Main loop
    while (!glfwWindowShouldClose(window)) 
    {
        // input
        processInput(window);
 
        // Specify the color of the background
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT); // Clean the back buffer and assign the new color to it

        // draw our first triangle
        glUseProgram(shaderProgram); // Tell OpenGL which Shader Program we want to use
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 3); // Draw the triangle using the GL_TRIANGLES primitive

 
        // Swap front and back buffers
        glfwSwapBuffers(window);
        // Poll for and process events
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
 
    // Terminate GLFW and clean up resources
    glfwTerminate();
    return 0;
}
