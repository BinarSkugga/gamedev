#include <bus/message.h>

Message::Message(const char *event) {
	this->event = event;
}

const char *Message::getEvent() {
	return this->event;
}
