#include "cube/ui.h"
#include "cube/program.h"
#include "cube/vao.h"

#include <glad/glad.h>
#include <glenn/glenn.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>

int main()
{
	Glenn::Initialize(800, 600, "Cube");

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glDepthFunc(GL_LEQUAL);

	const Cube::Program program;
	const Cube::VAO vao;

	const GLint modelLocation = glGetUniformLocation(program, "u_model");
	const GLint viewLocation = glGetUniformLocation(program, "u_view");
	const GLint projectionLocation = glGetUniformLocation(program, "u_projection");

	glm::mat4 model(1.0f);
	glm::mat4 view(1.0f);
	glm::mat4 projection(1.0f);

	Cube::UI::State uiState;

	while (Glenn::Begin())
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Cube::UI::Draw(uiState);

		const glm::mat4 rotation = glm::mat4_cast(glm::quat(glm::radians(uiState.rotation)));
		model = glm::scale(glm::translate(glm::mat4(1.0f), uiState.translation) * rotation, uiState.scale);
		view = glm::lookAt(uiState.cameraPosition, uiState.cameraTarget, uiState.up);
		projection = glm::perspective(uiState.fovY, uiState.aspectRatio, uiState.zNear, uiState.zFar);

		glUseProgram(program);

		glProgramUniformMatrix4fv(program, modelLocation, 1, GL_FALSE, glm::value_ptr(model));
		glProgramUniformMatrix4fv(program, viewLocation, 1, GL_FALSE, glm::value_ptr(view));
		glProgramUniformMatrix4fv(program, projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));

		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, vao.GetElementCount(), GL_UNSIGNED_INT, 0);

		Glenn::End();
	}

	Glenn::Shutdown();

	return 0;
}
