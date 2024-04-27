#include "cube/vao.h"
#include "cube/geometry.h"

Cube::VAO::VAO()
{
	glCreateVertexArrays(1, &this->id);
	glCreateBuffers(2, this->buffers);

	const GLuint vao{ this->id };
	const GLuint indexBuffer{ this->buffers[0] };
	const GLuint vertexBuffer{ this->buffers[1] };

	glNamedBufferStorage(indexBuffer, sizeof(Geometry::meshTriangles), Geometry::meshTriangles.data(), GL_DYNAMIC_STORAGE_BIT);
	glVertexArrayElementBuffer(vao, indexBuffer);

	this->elementCount = Geometry::meshTriangles.size() * std::tuple_size_v<Geometry::SimpleTriangle>;

	glNamedBufferStorage(vertexBuffer, sizeof(Geometry::meshVertices), Geometry::meshVertices.data(), GL_DYNAMIC_STORAGE_BIT);

	const GLuint bindingIndex{ 0 };
	const GLintptr offset{ 0 };
	glVertexArrayVertexBuffer(vao, bindingIndex, vertexBuffer, offset, sizeof(Geometry::SimpleVertex));

	const GLuint positionIndex{ 0 };
	glEnableVertexArrayAttrib(vao, positionIndex);
	glVertexArrayAttribFormat
	(
		vao,
		positionIndex,
		std::tuple_size_v<Geometry::SimpleVertex::Position>,
		GL_FLOAT,
		GL_FALSE, // normalized
		offsetof(Geometry::SimpleVertex, position)
	);
	glVertexArrayAttribBinding(vao, positionIndex, bindingIndex);

	const GLuint colorIndex{ 1 };
	glEnableVertexArrayAttrib(vao, colorIndex);
	glVertexArrayAttribFormat
	(
		vao,
		colorIndex,
		std::tuple_size_v<Geometry::SimpleVertex::Color>,
		GL_FLOAT,
		GL_FALSE, // normalized
		offsetof(Geometry::SimpleVertex, color)
	);
	glVertexArrayAttribBinding(vao, colorIndex, bindingIndex);
}

Cube::VAO::~VAO()
{
	glDeleteBuffers(2, this->buffers);
	glDeleteVertexArrays(1, &this->id);
}

Cube::VAO::operator GLuint() const
{
	return this->id;
}

GLuint Cube::VAO::GetElementCount() const
{
	return this->elementCount;
}
