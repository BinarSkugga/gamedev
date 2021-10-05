#include <GLFW/glfw3.h>
#include <key.h>

Key::Key(GLFWwindow* window, int code) {
	this->window = window;
	this->code = code;
}

int Key::getKeyState() const {
	return this->state;
}

int Key::getGLFWState() const {
	return glfwGetKey(this->window, this->code);
}

bool Key::isIdle() const {
	return this->state == 0;
}

bool Key::isPressed() const {
	return this->state == 1;
}

bool Key::isReleased() const {
	return this->state == -1;
}

void Key::init() {
	int current_state = this->getGLFWState();

	switch(current_state) {
		case 0:
			// Key Released
			if(this->state == 1)
				this->state = -1;
			break;
		default:
			this->state = current_state;
			break;
	}

}

void Key::destroy() {

}

Key::~Key() {

}
