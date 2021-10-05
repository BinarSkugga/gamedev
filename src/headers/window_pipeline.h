#pragma once

#include <gl_pipeline.h>
#include <window.h>

class WindowPipeline : public virtual GLPipeline {
	protected:
		void processObject(GLObject* obj) override;
};