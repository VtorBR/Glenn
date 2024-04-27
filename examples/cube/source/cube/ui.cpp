#include "cube/ui.h"

#include <imgui/imgui.h>
#include <glm/glm/gtc/type_ptr.hpp>

void Cube::UI::Draw(State& state)
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("Window"))
		{
			ImGui::MenuItem("Model", nullptr, &state.showModel);
			ImGui::MenuItem("View", nullptr, &state.showView);
			ImGui::MenuItem("Projection", nullptr, &state.showProjection);
			ImGui::Separator();
			ImGui::MenuItem("Demo", nullptr, &state.showDemo);
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}

	if (state.showModel)
	{
		ImGui::Begin("Model", &state.showModel);
		ImGui::DragFloat3("Translation", glm::value_ptr(state.translation), 0.1f);
		ImGui::DragFloat3("Rotation", glm::value_ptr(state.rotation), 1.0f);
		ImGui::DragFloat3("Scale", glm::value_ptr(state.scale), 0.1f);
		ImGui::End();
	}

	if (state.showView)
	{
		ImGui::Begin("View", &state.showView);
		ImGui::DragFloat3("Camera position", glm::value_ptr(state.cameraPosition), 0.1f);
		ImGui::DragFloat3("Camera target", glm::value_ptr(state.cameraTarget), 0.1f);
		ImGui::DragFloat3("Up", glm::value_ptr(state.up), 0.1f);
		ImGui::End();
	}

	if (state.showProjection)
	{
		ImGui::Begin("Projection", &state.showProjection);
		ImGui::DragFloat("FOV", &state.fovY, 0.1f);
		ImGui::DragFloat("Aspect ratio", &state.aspectRatio, 0.1f);
		ImGui::DragFloat("Near", &state.zNear, 0.1f);
		ImGui::DragFloat("Far", &state.zFar, 0.1f);
		ImGui::End();
	}

	if (state.showDemo)
	{
		ImGui::ShowDemoWindow(&state.showDemo);
	}
}
