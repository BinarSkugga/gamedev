#pragma once

class GLObject {
	public:
		GLObject() = default;
	protected:
		virtual void init() {}
		virtual void destroy() {}
};