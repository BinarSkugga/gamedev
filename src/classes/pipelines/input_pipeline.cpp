#include <iostream>
#include <scroll_key.h>

#include "pipelines/input_pipeline.h"
#include "key.h"


InputPipeline::InputPipeline(GLFWwindow* window) {
	InputPipeline::scrollKey = new ScrollKey(window);
	this->add(InputPipeline::scrollKey);

	glfwSetScrollCallback(window, [](GLFWwindow* win, double xoffset, double yoffset) {
		InputPipeline::scrollKey->updateOffset(yoffset);
	});
}

void InputPipeline::processObject(Key* key) {
	if(key->getCode() == InputPipeline::scrollKey->getCode() and InputPipeline::scrollKey->scrolled()) {
		this->bus.send(Message<Key>("scroll", key));
	}
}
