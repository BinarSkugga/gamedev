#pragma once

#include "key.h"
#include "gl_pipeline.h"
#include "bus/message_bus.h"

#define SCROLL_UP_KEY 1000
#define SCROLL_DOWN_KEY 1001


class InputPipeline : public GLPipeline<Key> {
	private:
		inline static InputPipeline* pipeline;
		inline static Key* scrollUpKey;
		inline static Key* scrollDownKey;

	public:
		explicit InputPipeline(GLFWwindow* window);

	protected:
		void processObject(Key* obj) override;
};
