#pragma once

#include <bus/message.h>
#include <vector>

class BusSubscriber {
	private:
		std::vector<const char*> subscriptions;
	public:
		void subscribe(const char* event);
		virtual void handle(Message* message) = 0;

		bool isSubscribed(const char* event);
};
