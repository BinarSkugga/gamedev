#include <chrono>
#include <thread>
#include <iostream>
#include "GLFW/glfw3.h"
#include "clock.h"

using namespace std;

Clock::Clock() {
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

bool Clock::isCompletedSecond() const {
	return this->completedSecond;
}

void Clock::update(int fpsCap) {
	this->completedSecond = false;

	double timePerFrame = 1.0 / ((this->manual) ? this->manualCap : fpsCap);
	double frameTime = glfwGetTime();
	double deltaTime = frameTime - this->tikTime;
	double remainingTime = timePerFrame - deltaTime;
	this_thread::sleep_for(chrono::microseconds((long)(remainingTime * 1000000)));

	this->runningFPS++;
	this->delta = glfwGetTime() - frameTime;
	this->runningTime += this->delta;

	if(this->runningTime >= 1.0) {
		this->FPS = this->runningFPS;
		this->runningFPS = 0;
		this->runningTime = 1.0 - this->runningTime;
		this->completedSecond = true;
	}

	this->tikTime = glfwGetTime();
}

void Clock::handle(Message *message) {
	this->manual = true;
	if(std::string(message->getEvent()) == "up")
		this->manualCap += 1;
	if(std::string(message->getEvent()) == "down")
		this->manualCap -= 1;
}
