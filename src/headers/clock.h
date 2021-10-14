#pragma once


#include "bus/bus_subscriber.h"
#include "key.h"

class Clock : public BusSubscriber<Key> {
	private:
		bool manual{false};
		int manualCap{120};

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

		void handle(const Message<Key>* message) override;
};


