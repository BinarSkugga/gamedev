#pragma once

#include "key.h"
#include "scroll_key.h"
#include "gl_pipeline.h"
#include "bus/message_bus.h"


class InputPipeline : public GLPipeline<Key> {
	private:
		inline static ScrollKey* scrollKey;

	public:
		explicit InputPipeline(GLFWwindow* const window);

	protected:
		void processObject(Key* const obj) override;
};
