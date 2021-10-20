#include <GL/glew.h>
#include <iostream>
#include "window.h"
#include "clock.h"
#include "GLFW/glfw3.h"
#include "pipelines/window_pipeline.h"
#include "pipelines/input_pipeline.h"
#include "key.h"
#include "shader/shader.h"


void WindowPipeline::processObject(Window* const window) {
	GLFWwindow* glwin = window->getGLFW();

	InputPipeline ipl = InputPipeline(glwin);
	ipl.add({
			        new Key(glwin, GLFW_KEY_W),
			        new Key(glwin, GLFW_KEY_A),
			        new Key(glwin, GLFW_KEY_S),
			        new Key(glwin, GLFW_KEY_D)
	        });

	Clock clock = Clock();
	clock.subscribe("scroll");
	ipl.bus.addSubscriber(&clock);

	Shader* vshader = new Shader("shaders/main.vert", GL_VERTEX_SHADER);
	Shader* fshader = new Shader("shaders/main.frag", GL_FRAGMENT_SHADER);

	float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f,  0.5f, 0.0f
	};

	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);

	unsigned int program;
	program = glCreateProgram();
	glAttachShader(program, vshader->getID());
	glAttachShader(program, fshader->getID());
	glLinkProgram(program);

	int success;
	char* infoLog;
	glGetProgramiv(program, GL_LINK_STATUS, &success);

	if(!success) {
		infoLog = (char*) malloc(GL_INFO_LOG_LENGTH);
		glGetProgramInfoLog(program, GL_INFO_LOG_LENGTH, nullptr, infoLog);
		std::cerr << "Failed to compile shader: " << infoLog << "\n";
		delete infoLog;
	}

	while(!glfwWindowShouldClose(glwin)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// START RENDER HERE

		glUseProgram(program);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// END RENDER HERE

		glfwSwapBuffers(glwin);
		glfwPollEvents();

		ipl.process(true);

		if(clock.isCompletedSecond()) {
			std::string subtitle = std::to_string(clock.getFPS()) + "fps, " + std::to_string(clock.getDeltaMS()) + "ms";
			window->setSubtitle(subtitle.c_str());
		}

		clock.update(window->isFocused() ? 120 : 10);
	}
}
