#pragma once

#include "gl_pipeline.h"

class WindowPipeline : public virtual GLPipeline<Window> {
	protected:
		void processObject(Window* obj) override;
};