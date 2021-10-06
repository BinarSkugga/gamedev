#include <clock.h>

#include <GLFW/glfw3.h>
#include <gl_object.h>
#include <window.h>
#include <window_pipeline.h>
#include <keyboard_pipeline.h>
#include <key.h>

void WindowPipeline::processObject(GLObject *obj) {
	Window* window = dynamic_cast<Window*>(obj);
	GLFWwindow* glwin = window->getGLFW();

	KeyboardPipeline* kpl = new KeyboardPipeline();
	Key wKey = Key(glwin, GLFW_KEY_W);
	Key aKey = Key(glwin, GLFW_KEY_A);
	Key sKey = Key(glwin, GLFW_KEY_S);
	Key dKey = Key(glwin, GLFW_KEY_D);

	kpl->add(&wKey);
	kpl->add(&aKey);
	kpl->add(&sKey);
	kpl->add(&dKey);

	Clock clock = Clock();
	while(!glfwWindowShouldClose(glwin)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Render stuff here

		glfwSwapBuffers(glwin);
		glfwPollEvents();
		kpl->process(true);

		if(clock.isCompletedSecond()) {
			std::string subtitle = std::to_string(clock.getFPS()) + "fps, " + std::to_string(clock.getDeltaMS()) + "ms";
			window->setSubtitle(subtitle.c_str());
		}

		clock.update(window->isFocused() ? 120 : 24);
	}
}
