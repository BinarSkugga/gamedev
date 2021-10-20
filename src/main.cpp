#include <iostream>
#include <filesystem>

// Include glew before everything
#include "GL/glew.h"

#include "window.h"
#include "pipelines/window_pipeline.h"

int main(int argc, char* argv[]) {
	WindowPipeline wpl = WindowPipeline();
	Window* w = new Window("My Game");

	wpl.add(w);
	wpl.process();

    return 0;
}
