#pragma once

#include "gl_object.h"
#include <set>


class GLPipeline {
	private:
		std::set<GLObject*> objects;
	public:
		void remove(GLObject* obj);
		void remove(std::initializer_list<GLObject*> objs);
		void add(GLObject* obj);
		void add(std::initializer_list<GLObject*> objs);
		void process(bool parallel = false);

	protected:
		virtual void processObject(GLObject* obj) = 0;
};


