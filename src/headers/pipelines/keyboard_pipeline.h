#pragma once

#include <key.h>
#include "gl_pipeline.h"
#include "bus/message_bus.h"


class KeyboardPipeline : public GLPipeline<Key> {
	private:
		MessageBus<Key>* bus;

	public:
		explicit KeyboardPipeline(MessageBus<Key>* bus);

	protected:
		void processObject(Key* obj) override;
};
