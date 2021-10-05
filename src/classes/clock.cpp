#include <chrono>
#include <thread>
#include <GLFW/glfw3.h>
#include <clock.h>
#include <iostream>

using namespace std;

Clock::Clock(int maxFPS) {
	this->maxFPS = maxFPS;
	this->timePerFrame = 1.0 / this->maxFPS;
	this->tikTime = glfwGetTime();
}

int Clock::getFPS() const {
	return this->FPS;
}

double Clock::getDelta() const {
	return this->delta;
}

double Clock::getDeltaMS() const {
	return this->delta * 1000;
}

void Clock::update() {
	double frameTime = glfwGetTime();
	double deltaTime = frameTime - this->tikTime;
	double remainingTime = this->timePerFrame - deltaTime;
	this_thread::sleep_for(chrono::microseconds((long)(remainingTime * 1000000)));

	this->runningFPS++;
	this->delta = glfwGetTime() - frameTime;
	this->runningTime += this->delta;

	if(this->runningTime >= 1.0) {
		this->FPS = this->runningFPS;
		this->runningFPS = 0;
		this->runningTime = 1.0 - this->runningTime;

		std::cout << this->getFPS() << ", " << this->getDeltaMS() << "ms" << std::endl;
	}

	this->tikTime = glfwGetTime();
}
