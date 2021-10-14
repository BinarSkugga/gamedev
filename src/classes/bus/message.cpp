#include "key.h"
#include "window.h"
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
const char* Message<T>::getEvent() const {
	return this->event;
}

template<class T>
T* Message<T>::getData() const {
	return this->data;
}


template class Message<Key>;
template class Message<Window>;