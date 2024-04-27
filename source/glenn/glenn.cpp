#include "glenn/glenn.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cassert>

void Glenn::Initialize(unsigned int width, unsigned int heigth, const char* title)
{
    const int initialized = glfwInit();
    assert(GLFW_TRUE == initialized);

    GLFWwindow* window = glfwCreateWindow(width, heigth, title, nullptr, nullptr);
    assert(window);

    glfwMakeContextCurrent(window);
    gladLoadGL();

    glfwSwapInterval(1);
}

void Glenn::Begin()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

bool Glenn::ShouldClose()
{
    return glfwWindowShouldClose(glfwGetCurrentContext());
}

void Glenn::End()
{
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
}

void Glenn::Shutdown()
{
    glfwDestroyWindow(glfwGetCurrentContext());
    glfwTerminate();
}
