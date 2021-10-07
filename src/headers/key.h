#pragma once

#include "GLFW/glfw3.h"
#include "gl_object.h"


const int RELEASED = -1;
const int IDLE = 0;
const int PRESSED = 1;
const int HELD = 2;


class Key : public GLObject {
	private:
		GLFWwindow* window;
		int code;
		int state{IDLE};

		int consecutiveHit{1};
		double lastPress{0.0};
		double lastRelease{0.0};

	public:
		explicit Key(GLFWwindow* window, int code);

		int getCode() const;
		int getGLFWState() const;
		int getKeyState() const;
		int getConsecutiveHit() const;
		double getHeldTime() const;

		bool isIdle() const;
		bool isPressed(int consecutive = 1) const;
		bool isReleased() const;
		bool isHeld() const;

	protected:
		void init() override;
		void clean() override;
};
