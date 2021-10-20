#pragma once

#include <string>

class Shader {
	private:
		int id;
		std::string shaderCode{};

	public:
		explicit Shader(const char* filePath);
};
