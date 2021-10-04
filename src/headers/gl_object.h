#pragma once

class GLObject {
	public:
		GLObject() = default;

		virtual void init() {}
		virtual void destroy() {}
};