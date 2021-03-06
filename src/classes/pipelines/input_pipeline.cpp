#include <iostream>
#include "scroll_key.h"

#include "pipelines/input_pipeline.h"
#include "key.h"


InputPipeline::InputPipeline(GLFWwindow* const window) {
	InputPipeline::scrollKey = new ScrollKey(window);
	this->add(InputPipeline::scrollKey);

	glfwSetScrollCallback(window, [](GLFWwindow* win, double xoffset, double yoffset) {
		InputPipeline::scrollKey->updateOffset(yoffset);
	});
}

void InputPipeline::processObject(Key* const key) {
	if(key->getCode() == InputPipeline::scrollKey->getCode() and InputPipeline::scrollKey->scrolled()) {
		this->bus.send(Message<Key>("scroll", key));
	}

	if(key->getCode() == GLFW_KEY_F12 and key->isPressed()) {
		this->bus.send(Message<Key>("f12", key));
	}
}
