#include <window.h>
#include <window_pipeline.h>

int main() {
    Window* w = new Window("My Game");
	WindowPipeline* wpl = new WindowPipeline();

	wpl->add(w);
	wpl->process();

    return 0;
}
