#pragma once

#include <glm/vec3.hpp>

namespace Cube
{
    namespace UI
    {
        struct State
        {
			glm::vec3 translation{ 0.0f, 0.0f, 0.0f };
			glm::vec3 rotation{ 0.0f, 0.0f, 0.0f };
			glm::vec3 scale{ 1.0f, 1.0f, 1.0f };

			glm::vec3 cameraPosition{ 0.0f, 10.0f, 0.0f };
			glm::vec3 cameraTarget{ 0.0f, 0.0f, 0.0f };
			glm::vec3 up{ 0.0f, 0.0f, 1.0f };

			float fovY{ 0.5f };
			float aspectRatio{ 1.33333f };
			float zNear{ 0.01f };
			float zFar{ 100.0f };

			bool showModel{ false };
			bool showView{ false };
			bool showProjection{ false };
			bool showDemo{ false };
        };

        void Draw(State& state);
    }
}
