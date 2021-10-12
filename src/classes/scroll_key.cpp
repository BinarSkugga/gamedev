#include "scroll_key.h"


ScrollKey::ScrollKey(GLFWwindow *window) : Key(window, SCROLL_KEY, true) {}

void ScrollKey::updateOffset(int newOffset) {
	this->offset -= newOffset;
}

bool ScrollKey::scrolled(int consecutive) {
	if(consecutive == 0)
		return this->state != 0;
	return this->state != 0 and this->consecutiveHit == consecutive;
}

void ScrollKey::init() {
	// Has been idle for 100ms
	if(this->lastOffset == this->offset and glfwGetTime() - this->lastRelease > CONSECUTIVE_SCROLL_RESET) {
		this->state = 0;
		this->offset = 0;
		this->consecutiveHit = 1;
		this->lastRelease = 0.0;
	}
	// User scrolled
	else if(this->lastOffset != this->offset) {
		// The current state is 1 for scrolling down and -1 for scrolling up
		int currentState = (this->offset - this->lastOffset > 0) ? 1 : -1;
		if(currentState != this->state) this->consecutiveHit = 1;

		// Increased consecutive hits if user had scrolled in the same direction in the last 100ms
		if(this->state == currentState and glfwGetTime() - this->lastRelease < CONSECUTIVE_SCROLL_RESET) {
			if(this->consecutiveHit < 10)
				this->consecutiveHit += 1;
		}
		this->state = currentState;
		this->lastRelease = glfwGetTime();
	}

	this->lastOffset = this->offset;
}
