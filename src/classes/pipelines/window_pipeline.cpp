#include <GL/glew.h>
#include <iostream>
#include <cmath>
#include <shader/shader_program.h>
#include "window.h"
#include "clock.h"
#include "GLFW/glfw3.h"
#include "pipelines/window_pipeline.h"
#include "pipelines/input_pipeline.h"
#include "key.h"
#include "shader/shader.h"


void WindowPipeline::processObject(Window* const window) {
	GLFWwindow* glwin = window->getGLFW();
	window->subscribe("f12");

	InputPipeline ipl = InputPipeline(glwin);
	ipl.add({
			        new Key(glwin, GLFW_KEY_W),
			        new Key(glwin, GLFW_KEY_A),
			        new Key(glwin, GLFW_KEY_S),
			        new Key(glwin, GLFW_KEY_D),
					new Key(glwin, GLFW_KEY_F12)
	        });
	ipl.bus.addSubscriber(window);

	Clock clock = Clock();
	clock.subscribe("scroll");
	ipl.bus.addSubscriber(&clock);

	ShaderProgram mainProgram = ShaderProgram("main");

	float initialAngle = 90.0f;
	int pointCount = 25;
	float angleStep = 360.0f / pointCount;
	float radius = 0.5f;

	float vertices[3 * pointCount];
	for(int i = 0; i < pointCount; i++) {
		float currentAngle = initialAngle - (i * angleStep);
		int carret = 3 * i;
		vertices[carret] = radius * cos(currentAngle * M_PI / 180);
		vertices[carret + 1] = radius * sin(currentAngle * M_PI / 180);
		vertices[carret + 2] = 0.0f;

		// std::cout << std::fixed << vertices[carret] << ", " << vertices[carret + 1] << ", " << vertices[carret + 2] << "\n";
	}

	unsigned int indices[3 * (pointCount - 2)];
	for(unsigned int i = 0; i < pointCount; i++) {
		int carret = 3 * (i - 1);
		if(i == 1 or i == pointCount - 1) continue;
		if(i == 0) {
			indices[0] = 0;
			indices[1] = 2;
			indices[2] = 1;
		} else {
			indices[carret] = 0;
			indices[carret + 1] = i + 1;
			indices[carret + 2] = i;
		}

		// std::cout << indices[3 * i] << ", " << indices[(3 * i) + 1] << ", " << indices[(3 * i) + 2] << "\n";
	}

	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);

	while(!glfwWindowShouldClose(glwin)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// START RENDER HERE

		mainProgram.init();
		glBindVertexArray(vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glDrawElements(GL_TRIANGLES, (pointCount - 2) * 3, GL_UNSIGNED_INT, nullptr);

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
