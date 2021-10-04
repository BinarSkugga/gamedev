#pragma once

#include "gl_object.h"
#include <set>


class GLPipeline {
	private:
		set<GLObject*> objects;
	public:
		void add(GLObject* obj);
		void remove(GLObject* obj);

		virtual void process() {};
};


