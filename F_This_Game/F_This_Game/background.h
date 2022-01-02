#pragma once
#include "setup.h"

class background {
public:
	background();
	~background(){}
	void drawBackground();
private:
	SDL_Rect src, dest;

	SDL_Texture* Background;

};