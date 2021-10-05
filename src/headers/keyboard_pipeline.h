#pragma once

#include <gl_pipeline.h>


class KeyboardPipeline : public GLPipeline {
	protected:
		void processObject(GLObject* obj) override;
};
