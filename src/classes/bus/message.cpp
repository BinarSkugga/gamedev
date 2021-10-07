#include <key.h>
#include "bus/message.h"

template<class T>
Message<T>::Message(const char *eventName) {
	this->event = eventName;
}

template<class T>
Message<T>::Message(const char *eventName, T* data) : Message(eventName) {
	this->data = data;
}

template<class T>
const char* Message<T>::getEvent() {
	return this->event;
}

template<class T>
T* Message<T>::getData() {
	return this->data;
}


template class Message<Key>;