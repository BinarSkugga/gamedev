#include "scroll_key.h"


ScrollKey::ScrollKey(const GLFWwindow *window) : Key(window, SCROLL_KEY, true) {}

void ScrollKey::updateOffset(int newOffset) {
	this->offset -= newOffset;
}

bool ScrollKey::scrolled(int consecutive) {
	if(this->consecutiveHit == this->lastExposedConsecutiveHit and !this->firstHit)
		return false;
	this->lastExposedConsecutiveHit = this->consecutiveHit;

	if(consecutive == 0)
		return this->state != 0;
	return this->state != 0 and this->consecutiveHit == consecutive;
}

void ScrollKey::init() {
	this->firstHit = false;
	if(this->lastOffset == this->offset and glfwGetTime() - this->lastRelease > CONSECUTIVE_SCROLL_RESET) {
		this->state = 0;
		this->offset = 0;
		this->consecutiveHit = 1;
		this->lastRelease = 0.0;
	} else if(this->lastOffset != this->offset) {
		int currentState = (this->offset - this->lastOffset > 0) ? 1 : -1;

		if(this->state == currentState and glfwGetTime() - this->lastRelease <= CONSECUTIVE_SCROLL_RESET) {
			this->consecutiveHit += 1;
		} else {
			this->firstHit = true;
			this->consecutiveHit = 1;
		}

		this->state = currentState;
		this->lastRelease = glfwGetTime();
	}

	this->lastOffset = this->offset;
}
