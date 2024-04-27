#include "glenn/glenn.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include <imgui/backends/imgui_impl_glfw.h>

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
    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");
}

bool Glenn::ShouldClose()
{
    return glfwWindowShouldClose(glfwGetCurrentContext());
}

void Glenn::Begin()
{
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Glenn::End()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
}

void Glenn::Shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    
    glfwDestroyWindow(glfwGetCurrentContext());
    glfwTerminate();
}
