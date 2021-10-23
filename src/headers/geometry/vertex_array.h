#pragma once

#include <vector>
#include <gl_object.h>
#include "gl_graphic_buffer.h"

class VertexArray : GLObject {
	private:
		unsigned int id;
		GLGraphicBuffer* elementBuffer;
		std::vector<GLGraphicBuffer*> buffers;

	public:
		VertexArray(std::vector<int>* const indicesData, std::vector<float>* const verticesData);

		void init();
		void clean();
};