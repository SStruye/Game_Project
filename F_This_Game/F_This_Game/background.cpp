#include "background.h"
#include "textures.h"

//load background
background::background() {
	Background = textures::LoadTexture("assets/background.png");
	src.x = src.y = 0;
	src.w = 1024;
	dest.w = 1024;
	src.h = 640;
	dest.h = 640;
	dest.x = 0;
	dest.y = 0;
}

//render background onscreen
void background::drawBackground() {
	int type = 0;
	textures::Draw(Background, src, dest);
}
