#include <GL/glew.h>
#include "shader/fragment_shader.h"

FragmentShader::FragmentShader(const char* shaderName)
		: Shader(getShaderPath(shaderName, "frag"), GL_FRAGMENT_SHADER) {}
