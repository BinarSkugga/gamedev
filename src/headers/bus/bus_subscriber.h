#pragma once

#include <vector>
#include "message_bus.h"
#include "message.h"

class BusSubscriber {
	private:
		std::vector<const char*> subscriptions;
	public:
		void subscribe(const char* event);
		void listenTo(MessageBus* bus);
		virtual void handle(Message* message) = 0;

		bool isSubscribed(const char* event);
};
