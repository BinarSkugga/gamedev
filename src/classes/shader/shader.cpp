#include <string>
#include <fstream>
#include <iostream>

#include "GL/glew.h"
#include "shader/shader.h"

Shader::Shader(const char* filePath, int shaderType) {
	std::string line;
	std::ifstream shaderFile{filePath};

	if(shaderFile.is_open()) {
		while(getline(shaderFile, line)) {
			this->shaderCode += line + "\n";
		}
		shaderFile.close();

		const char* source = this->shaderCode.c_str();
		this->id = glCreateShader(shaderType);
		glShaderSource(this->id, 1, &source, nullptr);
		glCompileShader(this->id);

		int success;
		char* infoLog;
		glGetShaderiv(this->id, GL_COMPILE_STATUS, &success);

		if(!success) {
			infoLog = (char*) malloc(GL_INFO_LOG_LENGTH);
			glGetShaderInfoLog(this->id, GL_INFO_LOG_LENGTH, nullptr, infoLog);
			std::cerr << "Failed to compile shader: " << infoLog << "\n";
			delete infoLog;
		}
	} else {
		std::cerr << "Couldn't open shader file: " << filePath << "\n";
	}
}

int Shader::getID() const {
	return this->id;
}