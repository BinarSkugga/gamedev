#include <iostream>

#include <keyboard_pipeline.h>
#include <key.h>


void KeyboardPipeline::processObject(GLObject* obj) {
	Key* key = dynamic_cast<Key*>(obj);

	if(key->isReleased())
		std::cout << "Released, held for " << key->getHeldTime() << "s !\n";
	if(key->isPressed())
		std::cout << "Pressed (" << key->getConsecutiveHit() << ") !\n";
	if(key->isPressed(2))
		std::cout << "Double pressed !\n";
}
