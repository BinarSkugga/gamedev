#pragma once


#include <bus/bus_subscriber.h>

class Clock : public BusSubscriber {
	private:
		unsigned short FPS{0};
		unsigned short runningFPS{0};

		double delta{0.0};
		double runningTime{0.0};

		double tikTime{};
		bool completedSecond{false};

	public:
		explicit Clock();

		int getFPS() const;
		double getDelta() const;
		double getDeltaMS() const;
		bool isCompletedSecond() const;

		void update(int fpsCap = 120);

		void handle(Message* message);
};


