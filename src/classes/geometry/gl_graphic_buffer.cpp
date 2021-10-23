#include <GL/glew.h>
#include <iostream>
#include "geometry/gl_graphic_buffer.h"

bool isValidDrawMode(int drawMode) {
	return drawMode == GL_STATIC_DRAW or drawMode == GL_DYNAMIC_DRAW or drawMode == GL_STREAM_DRAW;
}

template<typename T>
void initializeBuffer(std::vector<T>* data, unsigned int* id, unsigned int* size, int* bufferType, int drawMode, bool elementBuffer) {
	if(!isValidDrawMode(drawMode))
		std::cerr << "Invalid draw mode: " << drawMode << "\n";

	*size = (int) data->size();
	T* arr_data = data->data();
	*bufferType = (elementBuffer) ? GL_ELEMENT_ARRAY_BUFFER : GL_ARRAY_BUFFER;

	glGenBuffers(1, id);
	glBindBuffer(*bufferType, *id);
	glBufferData(*bufferType, *size * sizeof(float), arr_data, drawMode);
}

template void initializeBuffer<float>(std::vector<float>* data, unsigned int* id, unsigned int* size, int* bufferType, int drawMode, bool elementBuffer);
template void initializeBuffer<int>(std::vector<int>* data, unsigned int* id, unsigned int* size, int* bufferType, int drawMode, bool elementBuffer);


GLGraphicBuffer::GLGraphicBuffer(std::vector<float>* data, int drawMode, bool elementBuffer) {
	initializeBuffer(data, &this->id, &this->size, &this->bufferType, drawMode, elementBuffer);
}

GLGraphicBuffer::GLGraphicBuffer(std::vector<int>* data, int drawMode, bool elementBuffer) {
	initializeBuffer(data, &this->id, &this->size, &this->bufferType, drawMode, elementBuffer);
}

GLGraphicBuffer::GLGraphicBuffer(std::vector<float>* data, bool elementBuffer) {
	initializeBuffer(data, &this->id, &this->size, &this->bufferType, GL_STATIC_DRAW, elementBuffer);
}

GLGraphicBuffer::GLGraphicBuffer(std::vector<int>* data, bool elementBuffer) {
	initializeBuffer(data, &this->id, &this->size, &this->bufferType, GL_STATIC_DRAW, elementBuffer);
}

GLGraphicBuffer::~GLGraphicBuffer() {
	glBindBuffer(this->bufferType, 0);
	glDeleteBuffers(1, &this->id);
}

void GLGraphicBuffer::bind() {
	glBindBuffer(this->bufferType, this->id);
}

unsigned int GLGraphicBuffer::getID() const {
	return this->id;
}

unsigned int GLGraphicBuffer::getSize() const {
	return this->size;
}

void GLGraphicBuffer::setBufferType(int bufferType) {
	this->bufferType = bufferType;
}
