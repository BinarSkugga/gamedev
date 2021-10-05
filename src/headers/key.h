#pragma once

#include <GLFW/glfw3.h>
#include <gl_object.h>

class Key : public GLObject {
	private:
		GLFWwindow* window;
		int code;
		int state{0};

	public:
		explicit Key(GLFWwindow* window, int code);
		virtual ~Key();

		int getGLFWState() const;
		int getKeyState() const;

		bool isIdle() const;
		bool isPressed() const;
		bool isReleased() const;

	protected:
		void init() override;
		void destroy() override;
};
