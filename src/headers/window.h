#pragma once

#include <GLFW/glfw3.h>
#include "gl_object.h"

class Window : GLObject {
	private:
		const int width{1280}, height{720}, x{0}, y{0};
		const char* title;
		GLFWwindow* window{};

	public:
		explicit Window(const char* title);
		~Window();

	protected:
		void init() override;
		void destroy() override;
};
