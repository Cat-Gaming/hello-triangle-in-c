#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string.h>

// the GL Program
GLuint program;


char load_shader_file(char filename[])
{
    FILE *file;
    char output[2048];

    file = fopen(filename, "r");
    fgets(output, 2048, file);
    fclose(file);

    return output;
}

void load_shader(char vs_filename, char fs_filename)
{
    char vs_source = load_shader_file((char)vs_filename);
    char fs_source = load_shader_file((char)fs_filename);

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vs, 1, (char)vs_source, strlen((char)vs_source));
    glShaderSource(fs, 1, (char)fs_source, strlen((char)fs_source));

    glCompileShader(vs);
    glCompileShader(fs);
    // WIP Debugging

    program = glCreateProgram();

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);

    // WIP
}

int main()
{

    // Window Initialization
    GLFWwindow* window;

    if (!glfwInit())
        return -1;
    
    window = glfwCreateWindow(800, 600, "Window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        printf("Error While Creating GLFW Window!\n");
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    // GLEW Initialization

    if (glewInit() != GLEW_OK)
    {
        printf("GLEW is Not Initalized Properly!");
        return -1;
    }

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    load_shader("shaders/basic.vert", "shaders/basic.frag");

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}