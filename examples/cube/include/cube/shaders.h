#pragma once

namespace Cube
{
	namespace Shaders
	{
		const char* vertexSource{ R"glsl(
#version 330 core

layout (location = 0) in vec3 a_position;
layout (location = 1) in vec3 a_color;

out vec3 v_color;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main()
{
    v_color = a_color;
    gl_Position = u_projection * u_view * u_model * vec4(a_position, 1.0);
}
)glsl" };

		const char* fragmentSource{ R"glsl(
#version 330 core

in vec3 v_color;

out vec4 f_color;

void main()
{
    f_color = vec4(v_color, 1.0);
}
)glsl" };
	}
}