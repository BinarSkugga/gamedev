#pragma once

template<class T>
class Message {
	private:
		const char* event{};
		T* data;

	public:
		explicit Message(const char* eventName);
		Message(const char* eventName, T* data);

		const char* getEvent() const;
		T* getData() const;
};
