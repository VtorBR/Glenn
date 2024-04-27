#include "blank/ui.h"

#include <glad/glad.h>
#include <glenn/glenn.h>

int main()
{
	Glenn::Initialize(800, 600, "Blank");

	while (Glenn::Begin())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		UI::DrawDemo();

		Glenn::End();
	}

	Glenn::Shutdown();

	return 0;
}
