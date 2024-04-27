#pragma once

namespace Glenn
{
    void Initialize(unsigned int width, unsigned int heigth, const char* title);
    void Begin();
    bool ShouldClose();
    void End();
    void Shutdown();
}
