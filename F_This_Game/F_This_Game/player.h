#pragma once
#include "setup.h"

class player {
public:
	player();
	~player(){}
	void update();
	void render();
	void jump();
	void collision(int gnd);
	bool reset();
	int x_Pos = 0;
	int y_Pos = 0;

private:
	bool isFalling = true;
	bool isCollided = false;
	int ground = 512;
	bool dead = false;
	SDL_Texture* objTexture;
	SDL_Rect srcR, destR ;
};