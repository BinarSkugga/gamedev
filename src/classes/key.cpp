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

double Key::getHeldTime() const {
	return this->lastRelease - this->lastPress;
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

	bool handled{false};
	if(current_state == IDLE) {
		// Key is currently idle but was pressed in the previous frame
		if(this->state == PRESSED or this->state == DOUBLE_PRESSED or this->state == HELD) {
			this->state = RELEASED;
			this->lastRelease = glfwGetTime();
			handled = true;
		}
	} else {
		// Key is currently pressed but was idle in the previous frame
		if(this->state == IDLE or this->state == RELEASED) {
			// Key was released less than 300ms ago
			if(glfwGetTime() - this->lastRelease < 0.3) {
				this->state = DOUBLE_PRESSED;
				this->lastPress = glfwGetTime();
				this->lastRelease = 0.0;
				handled = true;
			}
		// Key is currently pressed and stayed pressed
		} else if(this->state == PRESSED or this->state == DOUBLE_PRESSED or this->state == HELD) {
			this->state = HELD;
			handled = true;
		}
	}

	// Any other situation, assign the current state to the key
	if(!handled) {
		this->state = current_state;
		if(this->state == PRESSED)
			this->lastPress = glfwGetTime();
	}
}

void Key::destroy() {

}
