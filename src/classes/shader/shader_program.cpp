#include <GL/glew.h>
#include <iostream>
#include "shader/shader_program.h"

ShaderProgram::ShaderProgram(const char* shaderName) {
	this->id = glCreateProgram();
	VertexShader* vshader = new VertexShader(shaderName);
	FragmentShader* fshader = new FragmentShader(shaderName);

	glAttachShader(this->id, vshader->getID());
	glAttachShader(this->id, fshader->getID());
	glLinkProgram(this->id);

	int success;
	char* infoLog;
	glGetProgramiv(this->id, GL_LINK_STATUS, &success);

	if(success) {
		// Detach all shaders because the program is now linked
		glDetachShader(this->id, vshader->getID());
		glDetachShader(this->id, fshader->getID());
	} else {
		infoLog = (char*) malloc(GL_INFO_LOG_LENGTH);
		glGetProgramInfoLog(this->id, GL_INFO_LOG_LENGTH, nullptr, infoLog);
		std::cerr << "Failed to link shader program: " << infoLog << "\n";
		delete infoLog;
	}

	// Clean up shaders no matter what
	glDeleteShader(vshader->getID());
	glDeleteShader(fshader->getID());

	delete vshader;
	delete fshader;
}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(this->id);
}

void ShaderProgram::init() {
	glUseProgram(this->id);
}

void ShaderProgram::clean() {
	// glUseProgram(0);
}