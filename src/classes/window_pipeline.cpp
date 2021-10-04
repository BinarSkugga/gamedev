#include <window_pipeline.h>
#include <gl_object.h>

void WindowPipeline::processObject(GLObject *obj) {
	Window* window = dynamic_cast<Window*>(obj);

	while(!glfwWindowShouldClose(window->getWindow())) {
		glfwSwapBuffers(window->getWindow());
		glfwPollEvents();
	}
}
