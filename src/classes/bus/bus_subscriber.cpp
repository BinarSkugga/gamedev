#include <cstring>
#include <key.h>
#include "bus/bus_subscriber.h"
#include "bus/message_bus.h"

template<class T>
void BusSubscriber<T>::subscribe(const char *event) {
	this->subscriptions.push_back(event);
}

template<class T>
bool BusSubscriber<T>::isSubscribed(const char* event) {
	std::vector<const char*> subs = this->subscriptions;
	return std::any_of(subs.begin(), subs.end(), [event](const char* sub){
		return strcmp(sub, event) == 0;
	});
}

template<class T>
void BusSubscriber<T>::listenTo(MessageBus<T>* bus) {
	bus->addSubscriber(this);
}


template class BusSubscriber<Key>;