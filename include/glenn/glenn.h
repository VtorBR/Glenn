#pragma once

namespace Glenn
{
    void Initialize(unsigned int width, unsigned int heigth, const char* title);
    bool ShouldClose();
    void Begin();
    void End();
    void Shutdown();
}
