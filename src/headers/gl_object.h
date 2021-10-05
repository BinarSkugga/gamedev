#pragma once

class GLObject {
	public:
		GLObject() = default;

		virtual void init() = 0;
		virtual void destroy() = 0;
};