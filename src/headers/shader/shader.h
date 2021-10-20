#pragma once

#include <string>
#include <gl_object.h>

std::string getShaderPath(const char* shaderName, const char* extension);

class Shader {
	private:
		unsigned int id;
		std::string shaderCode{};

	public:
		Shader(std::string filePath, int shaderType);

		unsigned int getID() const;
};
