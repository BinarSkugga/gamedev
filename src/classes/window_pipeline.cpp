#include <window_pipeline.h>
#include <gl_object.h>
#include <clock.h>

void WindowPipeline::processObject(GLObject *obj) {
	Window* window = dynamic_cast<Window*>(obj);
	GLFWwindow* glwin = window->getGLFW();

	Clock* clock = new Clock();
	while(!glfwWindowShouldClose(glwin)) {
		glfwSwapBuffers(glwin);
		glfwPollEvents();

		// Render stuff here

		clock->update();
	}
}
