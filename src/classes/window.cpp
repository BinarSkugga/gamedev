#include <iostream>
#include <cstring>
#include "GL/glew.h"

#include "window.h"


Window::Window(const char* title) {
	this->title = title;
}

GLFWwindow* Window::getGLFW() {
	return this->window;
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
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	this->window = glfwCreateWindow(this->width, this->height, this->title, nullptr, nullptr);

	glfwMakeContextCurrent(this->window);
	glViewport(0, 0, this->width, this->height);
	glfwSwapInterval(0);

	glewExperimental = true;
	glewInit();

//	glfwSetInputMode(this->window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
//	glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GLFW_TRUE);
}

void Window::clean() {

}

void Window::handle(Message<Key>* const message) {
	Key* key = message->getData();

	if(key->getCode() == GLFW_KEY_F12) {
		GLint polygonMode;
		glGetIntegerv(GL_POLYGON_MODE, &polygonMode);

		if(polygonMode == GL_LINE)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
}

Window::~Window() {
	delete this->title;
	glfwDestroyWindow(this->window);
	glfwTerminate();
}
