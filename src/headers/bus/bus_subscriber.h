#pragma once

#include <vector>
#include "message_bus.h"
#include "message.h"

template<class T>
class BusSubscriber {
	private:
		std::vector<const char*> subscriptions;
	public:
		void subscribe(const char* event);
		void listenTo(MessageBus<T>* const bus);
		virtual void handle(Message<T>* const message) = 0;

		bool isSubscribed(const char* event) const;
};
