#include <iostream>

#include <pipelines/keyboard_pipeline.h>
#include <key.h>


KeyboardPipeline::KeyboardPipeline(MessageBus *bus) {
	this->bus = bus;
}

void KeyboardPipeline::processObject(GLObject* obj) {
	Key* key = dynamic_cast<Key*>(obj);

	if(key->isReleased())
		this->bus->send(Message("released"));
}
