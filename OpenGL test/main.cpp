#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "Shader.h"


// window dimensions
const GLint WIDTH = 800, HEIGHT = 600;


int main() {
    glfwInit();
    
    // idk really
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "test", nullptr, nullptr);

    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    
    if (nullptr == window) {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        
        return -1;
    }
    
    // set `window` to be the focus
    glfwMakeContextCurrent(window);
    
    // include new "experimental" features
    glewExperimental = GL_TRUE;
    
    if (GLEW_OK != glewInit()) {
        std::cout << "Failed to initialise GLEW" << std::endl;
        
        return -1;
    }
    
    glViewport(0, 0, screenWidth, screenHeight);
    
    Shader shader("resources/shaders/core.vs", "resources/shaders/core.frag");
    
    // vertices of the triangle
    GLfloat vertices[] = {
        // vertex           // colour
        -.5f, -.5f, .0f,    .4f, .1f, .3f,
        .5f, -.5f, .0f,     .5f, .1f, .1f,
        .0f, .5f, .0f,      .0f, .1f, .5f
    };
    
    // declare and generate vertex [buffer and array] objects
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    // bind data to objects
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    // buffer data being used to draw with
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // create vertex pointer + enable vertex array
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *) 0);
    glEnableVertexAttribArray(0);
    
    // repeat for colour
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    
    // unbind as no longer needed
    glBindVertexArray(0);
    
    
    // while app is open loop -----------------------
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClearColor(0.05f, 0.01f, 0.01f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // draw triangle
        shader.Use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // unbind
        glBindVertexArray(0);
        
        glfwSwapBuffers(window);
    }
    // ----------------------------------------------
    
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    
    glfwTerminate();
    
    return 0;
}
