#include "GLFW/glfw3.h"
#include "key.h"

Key::Key(GLFWwindow* const window, int code, bool isMouse) {
	this->window = window;
	this->code = code;
	this->isMouse = isMouse;
}

int Key::getCode() const {
	return this->code;
}

int Key::getKeyState() const {
	return this->state;
}

int Key::getConsecutiveHit() const {
	return this->consecutiveHit;
}

int Key::getGLFWState() const {
	if(this->isMouse) {
		return glfwGetMouseButton(this->window, this->code);
	} else {
		return glfwGetKey(this->window, this->code);
	}
}

double Key::getHeldTime() const {
	return this->lastRelease - this->lastPress;
}

bool Key::isIdle() const {
	return this->state == IDLE;
}

bool Key::isPressed(int consecutive) const {
	if(consecutive == 0)
		return this->state == PRESSED;
	return this->state == PRESSED and this->consecutiveHit == consecutive;
}

bool Key::isReleased() const {
	return this->state == RELEASED;
}

bool Key::isHeld() const {
	return this->state == HELD;
}

void Key::init() {
	int current_state = this->getGLFWState();

	bool handled{false};
	if(current_state == IDLE) {
		// Key is currently idle but was pressed in the previous frame
		if(this->state == PRESSED or this->state == HELD) {
			this->state = RELEASED;
			this->lastRelease = glfwGetTime();
			handled = true;
		}
	} else {
		// Key is currently pressed but was idle in the previous frame
		if(this->state == IDLE or this->state == RELEASED) {
			// Key was released less than 300ms ago
			if(glfwGetTime() - this->lastRelease <= CONSECUTIVE_RESET) {
				this->state = PRESSED;
				this->consecutiveHit += 1;
				this->lastPress = glfwGetTime();
				this->lastRelease = 0.0;
				handled = true;
			} else {
				this->consecutiveHit = 1;
			}
		// Key is currently pressed and stayed pressed
		} else if(this->state == PRESSED or this->state == HELD) {
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

void Key::clean() {

}
