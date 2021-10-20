#include <string>
#include <fstream>
#include <iostream>

#include "GL/glew.h"
#include "shader/shader.h"

Shader::Shader(const char* filePath) {
	std::string line;
	std::ifstream shaderFile{filePath};

	if(shaderFile.is_open()) {
		while(getline(shaderFile, line)) {
			this->shaderCode += line + "\n";
		}
		shaderFile.close();

		const char* source = this->shaderCode.c_str();
		this->id = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(this->id, 1, &source, NULL);
		glCompileShader(this->id);

		int success;
		char infoLog[512];
		glGetShaderiv(this->id, GL_COMPILE_STATUS, &success);

		if(!success) {
			glGetShaderInfoLog(this->id, 512, NULL, infoLog);
			std::cerr << "Failed to compile shader: " << infoLog << "\n";
		}
	} else {
		std::cerr << "Couldn't open shader file: " << filePath << "\n";
	}
}