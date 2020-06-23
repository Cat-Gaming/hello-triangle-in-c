#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

char load_shader_file(char filename[])
{
    FILE *file;
    char output[2048];

    file = fopen(filename, 'r');
    fgets(output, 2048, file);
    fclose(file);

    return output;
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
    

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}