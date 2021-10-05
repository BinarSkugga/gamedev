#include <iostream>
#include "window.h"


Window::Window(const char* title) {
	this->title = title;
}

GLFWwindow* Window::getGLFW() {
	return this->window;
}

const char* Window::getTitle() {
	return this->title;
}

bool Window::isFocused() const {
	return glfwGetWindowAttrib(this->window, GLFW_FOCUSED);
}

void Window::init() {
	glfwInit();

	this->window = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);
	glfwMakeContextCurrent(this->window);
	glfwSwapInterval(0);
}

void Window::destroy() {
	glfwDestroyWindow(this->window);
	glfwTerminate();
}

Window::~Window() {
	delete this->title;
}
