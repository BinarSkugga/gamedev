#pragma once

#include "gl_object.h"
#include "vertex_shader.h"
#include "fragment_shader.h"

class ShaderProgram : public GLObject {
	private:
		unsigned int id;

	protected:
		virtual ~ShaderProgram();

	public:
		explicit ShaderProgram(const char* shaderName);

		void init() override;
		void clean() override;
};