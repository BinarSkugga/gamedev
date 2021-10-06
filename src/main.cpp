#include <window.h>
#include <window_pipeline.h>

int main() {
	WindowPipeline wpl = WindowPipeline();
	Window* w = new Window("My Game");

	wpl.add(w);
	wpl.process();

    return 0;
}
