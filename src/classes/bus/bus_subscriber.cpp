#include <cstring>
#include "bus/bus_subscriber.h"
#include "bus/message_bus.h"

void BusSubscriber::subscribe(const char *event) {
	this->subscriptions.push_back(event);
}

bool BusSubscriber::isSubscribed(const char* event) {
	std::vector<const char*> subs = this->subscriptions;
	return std::any_of(subs.begin(), subs.end(), [event](const char* sub){
		return strcmp(sub, event) == 0;
	});
}

void BusSubscriber::listenTo(MessageBus* bus) {
	bus->addSubscriber(this);
}
