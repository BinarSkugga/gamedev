#include <iostream>
#include "GLFW/glfw3.h"

int main() {
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(1280, 720, "My Game", NULL, NULL);
    glfwMakeContextCurrent(window);

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Main loop
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
