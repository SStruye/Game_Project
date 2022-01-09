#include "obstacle.h"
#include "textures.h"
//create obstacle with needed texture
obstacle::obstacle(int typ, int x, int y) {
	if (typ == 0) {
		objTexture = textures::LoadTexture("assets/transparant.png");
	}
	if (typ == 1) {
		objTexture = textures::LoadTexture("assets/block.png");
	}
	if (typ == 2) {
		objTexture = textures::LoadTexture("assets/spike.png");
	}
	if (typ == 3) {
		objTexture = textures::LoadTexture("assets/floor.png");
	}
	if (typ == 4) {
		objTexture = textures::LoadTexture("assets/finish.png");
	}
	type = typ;
	x_Pos = x;
	y_Pos = y;
}
//update obstacle position
void obstacle::update() {
	destR.x = x_Pos;
	destR.y = y_Pos;
	srcR.h = 32;
	srcR.w = 32;
	srcR.x = 0;
	srcR.y = 0;
	destR.w = srcR.w * 2;
	destR.h = srcR.h * 2;
}
//move obstacle to left
int obstacle::move() {
	x_Pos -= 4;
	return x_Pos;
}
//obstacle renderer
void obstacle::render() {
	SDL_RenderCopy(setup::renderer, objTexture, &srcR, &destR);
}