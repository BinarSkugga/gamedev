#include "bus/message_bus.h"
#include "bus/bus_subscriber.h"


void MessageBus::addSubscriber(BusSubscriber* subscriber) {
	this->subscribers.push_back(subscriber);
}

void MessageBus::send(Message message) {
	this->messages.push(message);
}

void MessageBus::publish() {
	while(!this->messages.empty()) {
		for(BusSubscriber* sub : this->subscribers) {
			Message message = this->messages.front();
			if(sub->isSubscribed(message.getEvent()))
				sub->handle(&message);
		}

		this->messages.pop();
	}
}
