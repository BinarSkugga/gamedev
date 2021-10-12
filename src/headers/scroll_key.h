#pragma once

#include "key.h"

#define SCROLL_KEY 10000
#define CONSECUTIVE_SCROLL_RESET 0.2

class ScrollKey : public Key {
	private:
		int lastOffset{0}, offset{0};
	public:
		explicit ScrollKey(GLFWwindow* window);
		bool scrolled(int consecutive = 0);
		void updateOffset(int newOffset);

		void init() override;
};