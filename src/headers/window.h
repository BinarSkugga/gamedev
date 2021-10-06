#pragma once

#include <GLFW/glfw3.h>
#include <gl_object.h>

class Window : public GLObject {
	private:
		int width{1280}, height{720};
		const char* title;
		GLFWwindow* window{};

	public:
		explicit Window(const char* title);
		virtual ~Window();

		GLFWwindow* getGLFW();
		bool isFocused() const;

		void setSubtitle(const char* subtitle);

	protected:
		void init() override;
		void clean() override;
};
