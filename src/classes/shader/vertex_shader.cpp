#include <GL/glew.h>
#include "shader/vertex_shader.h"

VertexShader::VertexShader(const char* shaderName)
	: Shader(getShaderPath(shaderName, "vert"), GL_VERTEX_SHADER) {}