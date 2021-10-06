#pragma once

#include "gl_object.h"
#include <set>


class GLPipeline {
	private:
		std::set<GLObject*> objects;
	public:
		void remove(GLObject* obj);
		void add(GLObject* obj);
		void process(bool parallel = false);

	protected:
		virtual void processObject(GLObject* obj) = 0;
};


