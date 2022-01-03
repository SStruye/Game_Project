#pragma once
#include "recourses.h"

class setup {
public:
	setup();
	~setup();

	void init(const char* title, int w_window, int h_window);
	void EventHandler();
	void update();
	void render();
	void clean();
	void reset(bool isDead, bool isFinished);
	bool running() { return isRunning; }
	static SDL_Renderer* renderer;

private:
	SDL_Rect src, dest;
	SDL_Texture* startScreen;
	bool start = false;
	bool isRunning = false;
	bool playing = false;
	SDL_Window* window;
};