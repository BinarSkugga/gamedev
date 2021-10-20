#pragma once

#include <string>

class Shader {
	private:
		int id;
		std::string shaderCode{};
	public:
		Shader(const char* filePath, int shaderType);

		int getID() const;
};
