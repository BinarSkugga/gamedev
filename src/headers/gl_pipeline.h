#pragma once

#include <set>
#include "bus/message_bus.h"
#include "gl_object.h"


template<class T>
class GLPipeline {
	private:
		std::set<T*> objects;
		void processObj(T* obj);

	public:
		MessageBus<T> bus{};

		void remove(T* obj);
		void remove(std::initializer_list<T*> objs);
		void add(T* obj);
		void add(std::initializer_list<T*> objs);

		void process(bool parallel = false);

	protected:
		virtual void processObject(T* const obj) = 0;
};


