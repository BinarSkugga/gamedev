#include "clock.h"
#include "GLFW/glfw3.h"
#include "gl_object.h"
#include "window.h"
#include "pipelines/window_pipeline.h"
#include "pipelines/keyboard_pipeline.h"
#include "key.h"
#include "bus/message_bus.h"

void WindowPipeline::processObject(Window* window) {
	GLFWwindow* glwin = window->getGLFW();

	MessageBus mbKey = MessageBus<Key>();

	KeyboardPipeline kpl = KeyboardPipeline(&mbKey);
	Key* wKey = new Key(glwin, GLFW_KEY_W);
	Key* aKey = new Key(glwin, GLFW_KEY_A);
	Key* sKey = new Key(glwin, GLFW_KEY_S);
	Key* dKey = new Key(glwin, GLFW_KEY_D);
	Key* upKey = new Key(glwin, GLFW_KEY_UP);
	Key* downKey = new Key(glwin, GLFW_MOUSE_BUTTON_LEFT, true);
	kpl.add({wKey, aKey, sKey, dKey, upKey, downKey});

	Clock clock = Clock();
	clock.subscribe("up");
	clock.subscribe("down");
	clock.listenTo(&mbKey);

	while(!glfwWindowShouldClose(glwin)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Render stuff here

		glfwSwapBuffers(glwin);
		glfwPollEvents();

		kpl.process(true);
		mbKey.publish();

		if(clock.isCompletedSecond()) {
			std::string subtitle = std::to_string(clock.getFPS()) + "fps, " + std::to_string(clock.getDeltaMS()) + "ms";
			window->setSubtitle(subtitle.c_str());
		}

		clock.update(window->isFocused() ? 120 : 10);
	}
}
