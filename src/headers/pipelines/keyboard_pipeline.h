#pragma once

#include "key.h"
#include "gl_pipeline.h"
#include "bus/message_bus.h"


class KeyboardPipeline : public GLPipeline<Key> {
	protected:
		void processObject(Key* obj) override;
};
