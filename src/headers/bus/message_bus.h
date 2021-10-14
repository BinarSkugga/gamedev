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
		std::vector<const BusSubscriber<T>*> subscribers;
		std::queue<Message<T>> messages;

	public:
		void addSubscriber(const BusSubscriber<T>* subscriber);
		void send(Message<T> message);
		void publish();
};
