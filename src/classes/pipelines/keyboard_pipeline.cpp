#include <iostream>

#include "pipelines/keyboard_pipeline.h"
#include "key.h"


KeyboardPipeline::KeyboardPipeline(MessageBus<Key> *bus) {
	this->bus = bus;
}

void KeyboardPipeline::processObject(Key* key) {
	if(key->getCode() == GLFW_KEY_UP and (key->isPressed(0) or key->isHeld()))
		this->bus->send(Message<Key>("up", key));
	if(key->getCode() == GLFW_MOUSE_BUTTON_LEFT and (key->isPressed(0) or key->isHeld()))
		this->bus->send(Message<Key>("down", key));
}
