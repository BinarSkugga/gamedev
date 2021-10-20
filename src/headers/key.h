#pragma once

#include "GLFW/glfw3.h"
#include "gl_object.h"


#define CONSECUTIVE_RESET 0.3
#define RELEASED -1
#define IDLE 0
#define PRESSED 1
#define HELD 2

class Key : public GLObject {
	protected:
		GLFWwindow* window;
		int code;
		bool isMouse;
		int state{IDLE};

		int consecutiveHit{1};
		double lastPress{0.0};
		double lastRelease{0.0};

	public:
		Key(GLFWwindow* const window, int code, bool isMouse = false);

		int getCode() const;
		int getGLFWState() const;
		int getKeyState() const;
		int getConsecutiveHit() const;
		double getHeldTime() const;

		bool isIdle() const;
		bool isPressed(int consecutive = 1) const;
		bool isReleased() const;
		bool isHeld() const;

		void init() override;
		void clean() override;
};
