#include "player.h"
#include "textures.h"

player::player() {
	objTexture = textures::LoadTexture("assets/player.png");
	y_Pos = 512;
}

void player::update() {

	if (isFalling == false && y_Pos > ground-128) {		//380
		if (y_Pos > ground-64) { y_Pos -= 8; }			//448
		else if (y_Pos > ground-112) { y_Pos -= 6; }	//400
		else if (y_Pos > ground-124) { y_Pos -= 4; }	//388		
		else { y_Pos -= 1; }
	}
	else { isFalling = true; }
	
	if (y_Pos < ground && isFalling == true) {
		if (y_Pos < ground - 124) { y_Pos += 1; }			//388
		else if (y_Pos < ground - 112) { y_Pos += 4; }		//400
		else if (y_Pos < ground - 64) { y_Pos += 6; }		//448
		else { y_Pos += 8; }								//512
	}

	if (y_Pos > ground) {
		std::cout << "height corrected from " << y_Pos << " to " << ground << std::endl;
		y_Pos = ground;
		
	}

	destR.x = 468;
	destR.y = y_Pos;
	srcR.h = srcR.w = 32;
	srcR.x = srcR.y = 0;
	destR.w = srcR.w * 2;
	destR.h = srcR.h * 2;
}

void player::render() {
	SDL_RenderCopy(setup::renderer, objTexture, &srcR, &destR);
}

void player::collision(int gnd) {

	switch (gnd) {
	case 0:	if (y_Pos >= 448) { ground = 512; }
		  break;
	case 1: if (isFalling == true && y_Pos <= 448) ground = 448;
			else if (y_Pos > 448){ 
				std::cout << "dead by block" << std::endl;
				dead = true;
			}
		break;
	case 2: if (isFalling == true && y_Pos < 448) ground = 448;
			else if (y_Pos >= 448) ground = 512;
			if (y_Pos > 448) {
				std::cout << "dead by spike" << std::endl;
				dead = true;
			}
		break;
	default:
		break;
	}
}
void player::jump() {
	if (y_Pos == ground) {
		isFalling = false;
	}
}

bool player::reset() {
	return dead;
}
