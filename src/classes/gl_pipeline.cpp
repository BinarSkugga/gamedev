#include <execution>

#include "gl_pipeline.h"

void GLPipeline::add(GLObject* obj) {
	this->objects.insert(obj);
}

void GLPipeline::remove(GLObject* obj) {
	this->objects.erase(obj);
}

void GLPipeline::process(bool parallel) {
	if(parallel) {
		std::for_each(
				std::execution::par_unseq,
				this->objects.begin(),
				this->objects.end(),
				[this](GLObject* obj) {
					obj->init();
					this->processObject(obj);
					obj->destroy();
				}
		);
	} else {
		for(GLObject* obj : this->objects) {
			obj->init();
			this->processObject(obj);
			obj->destroy();
		}
	}
}
