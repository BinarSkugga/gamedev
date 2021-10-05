#include <iostream>

#include <keyboard_pipeline.h>
#include <key.h>

void KeyboardPipeline::processObject(GLObject* obj) {
	Key* key = dynamic_cast<Key*>(obj);

	std::cout << key->getKeyState() << std::endl;
}
