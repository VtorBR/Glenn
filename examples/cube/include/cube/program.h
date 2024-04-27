#pragma once

#include <glad/glad.h>

namespace Cube
{
    class Program
    {
    public:
        Program();
        ~Program();

        operator GLuint() const;

    private:
        GLuint id;
    };
}
