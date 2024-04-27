#pragma once

#include <array>
#include <cstdint>

namespace Cube
{
	namespace Geometry
	{
		struct SimpleVertex
		{
			using Position = std::array<float, 3>;
			using Color = std::array<float, 3>;

			Position position;
			Color color;
		};

		using SimpleTriangle = std::array<std::uint32_t, 3>;

		constexpr static std::array<SimpleVertex, 8> meshVertices
		{ {
			{
				{0.5f, -0.5f, -0.5f}, // 0
				{1.0f, 0.0f, 0.0f}, // red
			},
			{
				{0.5f, -0.5f, 0.5f}, // 1
				{1.0f, 0.0f, 1.0f}, // magenta
			},
			{
				{0.5f, 0.5f, -0.5f}, // 2
				{1.0f, 1.0f, 0.0f}, // yellow
			},
			{
				{0.5f, 0.5f, 0.5f}, // 3
				{1.0f, 1.0f, 1.0f}, // white
			},
			{
				{-0.5f, -0.5f, -0.5f}, // 4
				{0.0f, 0.0f, 0.0f}, // black
			},
			{
				{-0.5f, -0.5f, 0.5f}, // 5
				{0.0f, 0.0f, 1.0f}, // blue
			},
			{
				{-0.5f, 0.5f, -0.5f}, // 6
				{0.0f, 1.0f, 0.0f}, // green
			},
			{
				{-0.5f, 0.5f, 0.5f}, // 7
				{0.0f, 1.0f, 1.0f}, // cyan
			},
		} };

		constexpr static std::array<SimpleTriangle, 12> meshTriangles
		{ {
			{0, 2, 1},
			{1, 2, 3},
			{4, 5, 6},
			{5, 7, 6},
			{3, 6, 7},
			{2, 6, 3},
			{4, 0, 5},
			{5, 0, 1},
			{5, 1, 7},
			{7, 1, 3},
			{4, 6, 0},
			{6, 2, 0},
		} };
	}
}
