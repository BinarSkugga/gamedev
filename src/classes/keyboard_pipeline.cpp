#include <iostream>

#include <keyboard_pipeline.h>
#include <key.h>


void KeyboardPipeline::processObject(GLObject* obj) {
	Key* key = dynamic_cast<Key*>(obj);

	if(key->getKeyState() == -1)
		std::cout << "Released, held for " << key->getHeldTime() << "s !\n";

	else if(key->getKeyState() == 1)
		std::cout << "Pressed !\n";

	else if(key->getKeyState() == 3)
		std::cout << "Double pressed !\n";
}
