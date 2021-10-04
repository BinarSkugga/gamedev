#pragma once

#include "gl_object.h"
#include <set>


class GLPipeline {
	private:
		std::set<GLObject*> objects;
	public:
		virtual void remove(GLObject* obj);
		virtual void add(GLObject* obj);
		virtual void process();

	protected:
		virtual void processObject(GLObject* obj) {};
};


