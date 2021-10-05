#include <window_pipeline.h>
#include <gl_object.h>
#include <clock.h>

void WindowPipeline::processObject(GLObject *obj) {
	Window* window = dynamic_cast<Window*>(obj);
	GLFWwindow* glwin = window->getGLFW();

	Clock clock = Clock();
	int fpsCap;

	while(!glfwWindowShouldClose(glwin)) {
		glfwSwapBuffers(glwin);
		glfwPollEvents();

		// Render stuff here

		if(clock.isCompletedSecond()) {
			std::string subtitle = std::to_string(clock.getFPS()) + "fps, " + std::to_string(clock.getDeltaMS()) + "ms";
			window->setSubtitle(subtitle.c_str());
		}

		fpsCap = window->isFocused() ? 120 : 24;
		clock.update(fpsCap);
	}
}
