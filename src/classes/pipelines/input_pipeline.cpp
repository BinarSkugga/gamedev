#include <iostream>

#include "pipelines/input_pipeline.h"
#include "key.h"


InputPipeline::InputPipeline(GLFWwindow* window) {
	InputPipeline::pipeline = this;
	InputPipeline::scrollUpKey = new Key(window, SCROLL_UP_KEY);
	InputPipeline::scrollDownKey = new Key(window, SCROLL_DOWN_KEY);

	glfwSetScrollCallback(window, [](GLFWwindow* win, double xoffset, double yoffset) {
		if(yoffset > 0)
			InputPipeline::pipeline->bus.send(Message<Key>("scrup", InputPipeline::scrollUpKey));
		else if(yoffset < 0)
			InputPipeline::pipeline->bus.send(Message<Key>("scrdown", InputPipeline::scrollDownKey));
	});
}

void InputPipeline::processObject(Key* key) {

}
