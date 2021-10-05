#include <iostream>
#include <cstring>
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

void Window::setSubtitle(const char* subtitle) {
	if(strlen(this->title) + strlen(subtitle) + 4 > 255)
		throw std::invalid_argument("Window's full title can't be longer than 255 characters.");

	char fullTitle[255];
	strcpy(fullTitle, this->title);
	strcat(fullTitle, " - ");
	strcat(fullTitle, subtitle);

	glfwSetWindowTitle(this->window, fullTitle);
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
