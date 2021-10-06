#pragma once

class GLObject {
	public:
		virtual void init() = 0;
		virtual void destroy() = 0;
};