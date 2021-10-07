#pragma once

#include <vector>
#include <queue>
#include <bus/bus_subscriber.h>

class MessageBus {
	private:
		std::vector<BusSubscriber*> subscribers;
		std::queue<Message> messages;

	public:
		void addSubscriber(BusSubscriber* subscriber);
		void send(Message message);
		void publish();
};
