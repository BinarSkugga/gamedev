#include <window.h>
#include <window_pipeline.h>

int main() {
	Window w = Window("My Game");
	WindowPipeline wpl = WindowPipeline();

	wpl.add(&w);
	wpl.process();

    return 0;
}
