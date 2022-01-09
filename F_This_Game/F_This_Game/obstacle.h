#pragma once
#include "setup.h"

class obstacle {
public:
	obstacle(int texture, int x, int y);
	~obstacle(){};
	void update();
	void render();
	int move();
	int x_Pos = 0;
	int y_Pos = 0;
	int type = 0;
private:

	SDL_Texture* objTexture;
	SDL_Rect srcR, destR;
};