#pragma once


class Clock {
	private:
		unsigned short maxFPS{};
		unsigned short FPS{0};
		unsigned short runningFPS{0};

		double timePerFrame{};
		double delta{0.0};
		double runningTime{0.0};

		double tikTime{};

	public:
		explicit Clock(int maxFPS = 120);

		int getFPS() const;
		double getDelta() const;
		double getDeltaMS() const;
		void update();
};


