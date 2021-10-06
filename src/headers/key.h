#pragma once

#include <GLFW/glfw3.h>
#include <gl_object.h>


const int RELEASED = -1;
const int IDLE = 0;
const int PRESSED = 1;
const int HELD = 2;
const int DOUBLE_PRESSED = 3;


class Key : public GLObject {
	private:
		GLFWwindow* window;
		int code;
		int state{0};

		double lastPress{0.0};
		double lastRelease{0.0};

	public:
		explicit Key(GLFWwindow* window, int code);

		int getGLFWState() const;
		int getKeyState() const;
		double getHeldTime() const;

		bool isIdle() const;
		bool isPressed() const;
		bool isReleased() const;

	protected:
		void init() override;
		void destroy() override;
};
