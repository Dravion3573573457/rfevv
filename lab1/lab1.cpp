#define GLEW_DLL
#define GLFW_DLL

#include <iostream>
#include "GL\glew.h"
#include "GLFW\glfw3.h"

int main()
{
    glfwInit();
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: couldnt start\n");
        return 1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(512, 512, "Mainwindow", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    GLenum ret = glewInit();
    if (GLEW_OK != ret) {
        fprintf(stderr, "ERROR", glewGetErrorString(ret));
        return 1;
    }


    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.2, 0.3, 0.4, 0);

        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);

        glVertex2f(0.0, 0.5);
        glColor3f(0.5, 0.5, 0.0);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);

        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    glfwTerminate();
}