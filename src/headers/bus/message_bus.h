#pragma once

#include <vector>
#include <queue>
#include "gl_object.h"
#include "bus/message.h"

template<class>
class BusSubscriber;

template<class T>
class MessageBus {
	private:
		std::vector<BusSubscriber<T>*> subscribers;
		std::queue<Message<T>> messages;

	public:
		void addSubscriber(BusSubscriber<T>* const subscriber);
		void send(Message<T> message);
		void publish();
};
