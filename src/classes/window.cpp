#include "window.h"


Window::Window(const char* title) {
	this->title = title;
}

void Window::init() {
	glfwInit();

	this->window = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);
	glfwMakeContextCurrent(this->window);

	while(!glfwWindowShouldClose(this->window)) {
		glfwSwapBuffers(this->window);
		glfwPollEvents();
	}
}

void Window::destroy() {
	glfwDestroyWindow(this->window);
	glfwTerminate();
}

Window::~Window() {
	delete[] this->title;
}
