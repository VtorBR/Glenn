#include "cube/program.h"
#include "cube/shaders.h"

Cube::Program::Program()
	: id{ glCreateProgram() }
{
	const GLuint vertexShader{ glCreateShader(GL_VERTEX_SHADER) };
	glShaderSource(vertexShader, 1, &Shaders::vertexSource, nullptr);
	glCompileShader(vertexShader);

	const GLuint fragmentShader = { glCreateShader(GL_FRAGMENT_SHADER) };
	glShaderSource(fragmentShader, 1, &Shaders::fragmentSource, nullptr);
	glCompileShader(fragmentShader);

	const GLuint program{ this->id };
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Cube::Program::~Program()
{
	glDeleteProgram(this->id);
}

Cube::Program::operator GLuint() const
{
	return this->id;
}
