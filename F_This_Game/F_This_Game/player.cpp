#include "player.h"
#include "textures.h"

//load player with player texture at bottom middle of screen
player::player() {
	objTexture = textures::LoadTexture("assets/player.png");
	y_Pos = 512;
}
//function to update the player every frame
void player::update() {


	//calculations for player jump
	if (isFalling == false && y_Pos > ground-128) {		
		if (y_Pos > ground-64) { y_Pos -= 8; }			
		else if (y_Pos > ground-112) { y_Pos -= 6; }	
		else if (y_Pos > ground-124) { y_Pos -= 4; }			
		else { y_Pos -= 1; }
	}
	else { isFalling = true; }
	
	if (y_Pos < ground && isFalling == true) {
		if (y_Pos < ground - 124) { y_Pos += 1; }			
		else if (y_Pos < ground - 112) { y_Pos += 4; }		
		else if (y_Pos < ground - 64) { y_Pos += 6; }		
		else { y_Pos += 8; }								
	}
	if (y_Pos > ground) {
		std::cout << "height corrected from " << y_Pos << " to " << ground << std::endl;
		y_Pos = ground;
		
	}

	//dest rectangle for player
	destR.x = 468;
	destR.y = y_Pos;
	srcR.h = srcR.w = 32;
	srcR.x = srcR.y = 0;
	destR.w = srcR.w * 2;
	destR.h = srcR.h * 2;
}

//renderer for player
void player::render() {
	SDL_RenderCopy(setup::renderer, objTexture, &srcR, &destR);
}

//collision detection betweem obstacles and player
void player::collision(int gnd) {

	switch (gnd) {
	case 0:	if (y_Pos >= 448) { ground = 512; }
		  break;
	case 1: if (isFalling == true && y_Pos == 448) ground = 448;
			else if (y_Pos > 448){  
				std::cout << "dead by block" << std::endl;
				dead = true;
			}
		break;
	case 2: if (isFalling == true && y_Pos >= 448) ground = 512;
			if (y_Pos > 470) {
				std::cout << "dead by spike" << std::endl;
				dead = true;
			}
		break;
	default:
		break;
	}
}
//detection if the user makes the player jump
void player::jump() {
	if (y_Pos == ground) {
		isFalling = false;
	}
}
//reset game after player dies
bool player::reset() {
	return dead;
}
