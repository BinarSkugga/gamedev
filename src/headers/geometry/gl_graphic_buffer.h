#pragma once

#include <vector>


class GLGraphicBuffer {
	protected:
		unsigned int id{0};
		unsigned int size{0};
		int bufferType{0};

	public:
		explicit GLGraphicBuffer(std::vector<float>* data, int drawMode = GL_STATIC_DRAW, bool elementBuffer = false);
		explicit GLGraphicBuffer(std::vector<int>* data, int drawMode = GL_STATIC_DRAW, bool elementBuffer = false);
		GLGraphicBuffer(std::vector<float>* data, bool elementBuffer);
		GLGraphicBuffer(std::vector<int>* data, bool elementBuffer);
		~GLGraphicBuffer();

		void bind();

		unsigned int getID() const;
		unsigned int getSize() const;
		void setBufferType(int bufferType);
};