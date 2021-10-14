#pragma once

#include <set>
#include "bus/message_bus.h"
#include "gl_object.h"


template<class T>
class GLPipeline {
	private:
		std::set<const T*> objects;
		void processObj(const T* obj);

	public:
		MessageBus<T> bus{};

		void remove(const T* obj);
		void remove(std::initializer_list<const T*> objs);
		void add(const T* obj);
		void add(std::initializer_list<const T*> objs);

		void process(bool parallel = false);

	protected:
		virtual void processObject(T* obj) = 0;
};


