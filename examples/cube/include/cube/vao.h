#pragma once

#include <glad/glad.h>

namespace Cube
{
    class VAO
    {
    public:
        VAO();
        ~VAO();

        operator GLuint() const;
        GLuint GetElementCount() const;

    private:
        GLuint id;
        GLuint buffers[2];
        GLuint elementCount;
    };
}
