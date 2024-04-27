#include "blank/ui.h"

#include <glenn/glenn.h>

int main()
{
	Glenn::Initialize(800, 600, "Blank");

	while (!Glenn::ShouldClose())
	{
		Glenn::Begin();

		UI::DrawDemo();

		Glenn::End();
	}

	Glenn::Shutdown();

	return 0;
}
