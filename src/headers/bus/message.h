#pragma once

class Message {
	private:
		const char* event;

	public:
		explicit Message(const char* event);
		const char* getEvent();
};
