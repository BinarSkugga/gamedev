#include <window_pipeline.h>
#include <gl_object.h>
#include <clock.h>

void WindowPipeline::processObject(GLObject *obj) {
	Window* window = dynamic_cast<Window*>(obj);
	GLFWwindow* glwin = window->getGLFW();

	Clock clock = Clock();
	while(!glfwWindowShouldClose(glwin)) {
		glfwSwapBuffers(glwin);
		glfwPollEvents();

		// Render stuff here

		if(clock.isCompletedSecond()) {
			std::string fullTitle = window->getTitle();
			fullTitle += " - " + std::to_string(clock.getFPS()) + "fps, " + std::to_string(clock.getDeltaMS()) + "ms";
			glfwSetWindowTitle(glwin, fullTitle.c_str());
		}
		clock.update();
	}
}
