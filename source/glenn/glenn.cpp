#include "glenn/glenn.h"
#include <GLFW/glfw3.h>
#include <cassert>

void Glenn::Initialize()
{
    const int initialized = glfwInit();
    assert(GLFW_TRUE == initialized);
}

void Glenn::Shutdown()
{
    glfwTerminate();
}
