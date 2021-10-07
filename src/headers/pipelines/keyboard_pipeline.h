#pragma once

#include "gl_pipeline.h"
#include "bus/message_bus.h"


class KeyboardPipeline : public GLPipeline {
	private:
		MessageBus* bus;

	public:
		explicit KeyboardPipeline(MessageBus* bus);

	protected:
		void processObject(GLObject* obj) override;
};
