#pragma once

#include <bus/bus_subscriber.h>
#include "GLFW/glfw3.h"

#include "gl_object.h"
#include "key.h"

class Window : public GLObject, public BusSubscriber<Key> {
	private:
		int width{1280}, height{720};
		const char* title;
		GLFWwindow* window{};

	public:
		explicit Window(const char* title);
		virtual ~Window();

		GLFWwindow* getGLFW();
		bool isFocused() const;

		void setSubtitle(const char* subtitle);

		void init() override;
		void clean() override;

		void handle(Message<Key>* const message);
};
