#include <iostream>
#include "window.h"


Window::Window(const char* title) {
	this->title = title;
}

GLFWwindow* Window::getWindow() {
	return this->window;
}

void Window::init() {
	glfwInit();

	this->window = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);
	glfwMakeContextCurrent(this->window);
}

void Window::destroy() {
	glfwDestroyWindow(this->window);
	glfwTerminate();
}

Window::~Window() {
	delete[] this->title;
}
