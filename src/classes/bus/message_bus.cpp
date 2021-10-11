#include "key.h"
#include "window.h"
#include "bus/message_bus.h"
#include "bus/bus_subscriber.h"


template<class T>
void MessageBus<T>::addSubscriber(BusSubscriber<T>* subscriber) {
	this->subscribers.push_back(subscriber);
}

template<class T>
void MessageBus<T>::send(Message<T> message) {
	this->messages.push(message);
}

template<class T>
void MessageBus<T>::publish() {
	while(!this->messages.empty()) {
		for(BusSubscriber<T>* sub : this->subscribers) {
			Message message = this->messages.front();
			if(sub->isSubscribed(message.getEvent()))
				sub->handle(&message);
		}

		this->messages.pop();
	}
}


template class MessageBus<Key>;
template class MessageBus<Window>;