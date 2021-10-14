#include <execution>
#include "window.h"
#include "key.h"

#include "gl_pipeline.h"

template<class T>
void GLPipeline<T>::add(const T* obj) {
	this->objects.insert(obj);
}

template<class T>
void GLPipeline<T>::add(std::initializer_list<const T*> objs) {
	this->objects.insert(objs);
}

template<class T>
void GLPipeline<T>::remove(const T* obj) {
	this->objects.erase(obj);
}

template<class T>
void GLPipeline<T>::remove(std::initializer_list<const T*> objs) {
	for(const T* obj : objs)
		this->remove(obj);
}

template<class T>
void GLPipeline<T>::processObj(const T* obj) {
	T* nonConst = const_cast<T*>(obj);

	nonConst->init();
	this->processObject(nonConst);
	nonConst->clean();
}

template<class T>
void GLPipeline<T>::process(bool parallel) {
	if(parallel) {
		std::for_each(
				std::execution::par_unseq,
				this->objects.begin(),
				this->objects.end(),
				[this](const T* obj) {
					this->processObj(obj);
				}
		);
	} else {
		for(const T* obj : this->objects) {
			this->processObj(obj);
		}
	}

	this->bus.publish();
}

template class GLPipeline<Window>;
template class GLPipeline<Key>;
