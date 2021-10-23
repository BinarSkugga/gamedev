#include <GL/glew.h>
#include "geometry/vertex_array.h"

VertexArray::VertexArray(std::vector<int>* const indicesData, std::vector<float>* const verticesData) {
	glGenVertexArrays(1, &this->id);
	glBindVertexArray(this->id);

	this->elementBuffer = new GLGraphicBuffer(indicesData, true);

	this->buffers.push_back(new GLGraphicBuffer(verticesData));
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);
}

void VertexArray::init() {
	glBindVertexArray(this->id);
	glDrawElements(GL_TRIANGLES, this->elementBuffer->getSize(), GL_UNSIGNED_INT, nullptr);
}

void VertexArray::clean() {}
