#include <iostream>

#include "pipelines/keyboard_pipeline.h"
#include "key.h"


void KeyboardPipeline::processObject(Key* key) {
	if(key->getCode() == GLFW_KEY_UP and (key->isPressed(0) or key->isHeld()))
		this->bus.send(Message<Key>("up", key));
	if(key->getCode() == GLFW_KEY_DOWN and (key->isPressed(0) or key->isHeld()))
		this->bus.send(Message<Key>("down", key));
}
