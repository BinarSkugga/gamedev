#include <execution>
#include "window.h"
#include "key.h"

#include "gl_pipeline.h"

template<class T>
void GLPipeline<T>::add(T* obj) {
	this->objects.insert(obj);
}

template<class T>
void GLPipeline<T>::add(std::initializer_list<T*> objs) {
	this->objects.insert(objs);
}

template<class T>
void GLPipeline<T>::remove(T* obj) {
	this->objects.erase(obj);
}

template<class T>
void GLPipeline<T>::remove(std::initializer_list<T*> objs) {
	for(T* const obj : objs)
		this->objects.erase(obj);
}

template<class T>
void GLPipeline<T>::processObj(T* obj) {
	obj->init();
	this->processObject(obj);
	obj->clean();
}

template<class T>
void GLPipeline<T>::process(bool parallel) {
	if(parallel) {
		std::for_each(
				std::execution::par_unseq,
				this->objects.begin(),
				this->objects.end(),
				[this](T* obj) {
					this->processObj(obj);
				}
		);
	} else {
		for(T* obj : this->objects) {
			this->processObj(obj);
		}
	}

	this->bus.publish();
}

template class GLPipeline<Window>;
template class GLPipeline<Key>;
