#include <glenn/glenn.h>

int main()
{
	Glenn::Initialize(800, 600, "Blank");

	while (!Glenn::ShouldClose())
	{
		Glenn::Begin();
		Glenn::End();
	}

	Glenn::Shutdown();

	return 0;
}
