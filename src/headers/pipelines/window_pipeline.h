#pragma once

#include "gl_pipeline.h"

class WindowPipeline : public virtual GLPipeline {
	protected:
		void processObject(GLObject* obj) override;
};