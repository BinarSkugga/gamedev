#include "gl_pipeline.h"

void GLPipeline::add(GLObject* obj) {
	this->objects.insert(obj);
}

void GLPipeline::remove(GLObject* obj) {
	this->objects.erase(obj);
}
