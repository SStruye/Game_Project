#include "level.h"
#include "obstacle.h"
#include "textures.h"
#include <vector>
#include <iostream>
using namespace std;




level::level() {
	fillVector(Obstacles, lvl[0]);

	zero = textures::LoadTexture("assets/numbers/number_0.png");
	one = textures::LoadTexture("assets/numbers/number_1.png");
	two = textures::LoadTexture("assets/numbers/number_2.png");
	three = textures::LoadTexture("assets/numbers/number_3.png");
	four = textures::LoadTexture("assets/numbers/number_4.png");
	five = textures::LoadTexture("assets/numbers/number_5.png");
	six = textures::LoadTexture("assets/numbers/number_6.png");
	seven = textures::LoadTexture("assets/numbers/number_7.png");
	eight = textures::LoadTexture("assets/numbers/number_8.png");
	nine = textures::LoadTexture("assets/numbers/number_9.png");

	singlesrcR.x = singlesrcR.y = decsrcR.x = decsrcR.y = 0;
	singlesrcR.w = 32;
	singledestR.w = 64;
	singlesrcR.h = 32;
	singledestR.h = 64;
	singledestR.x = 928;
	singledestR.y = 50;

	decsrcR.w = 32;
	decdestR.w = 64;
	decsrcR.h = 32;
	decdestR.h = 64;
	decdestR.x = 864;
	decdestR.y = 50;
};

//add new obstacle to vector
void level::fillVector(vector<obstacle>&newAdd, int type) {
	switch (type) {
	case 0: type = 0;
		break;
	case 1: type = 1;
		break;
	case 2: type = 2;
		break;
	default:
		break;
	}
	obstacle newObstacle(type, 1024, 512);
	newAdd.push_back(newObstacle);
}

//function to update the level every frame(same principal as floor::update)
void level::update() {
	unsigned int size = Obstacles.size();
	for (unsigned int i = 0; i < size; i++) {
		Obstacles[i].move();
		Obstacles[i].update();
	}
	if (Obstacles[0].x_Pos <= -64) {
		Obstacles.erase(Obstacles.begin());
		Collision.erase(Collision.begin());
		Obstacles.shrink_to_fit();
		Collision.shrink_to_fit();
	}
	cnt++;
	if (cnt == 16) {
		if (iterator < 64) {
			fillVector(Obstacles, lvl[iterator]);
			Collision.push_back(lvl[iterator]);
		}	
		iterator++;
		cnt = 0;
	}
	if (iterator == lvlSize+9) {
		finished = true;
	}
}

//reset game when lvl is finished
bool level::reset() {
	return finished;
}

//renders the obstacles and the scoreboard
void level::render() {
	unsigned int size = Obstacles.size();
	for (unsigned int i = 0; i < size; i++) {
		Obstacles[i].render();
	}

	//pixel art scoreboard generation
	int singleN = iterator % 10;
	int decN = (iterator - iterator % 10) / 10;
	switch (singleN) {
	case 0: SDL_RenderCopy(setup::renderer, zero, &singlesrcR, &singledestR);
		break;
	case 1: SDL_RenderCopy(setup::renderer, one, &singlesrcR, &singledestR);
		break;
	case 2: SDL_RenderCopy(setup::renderer, two, &singlesrcR, &singledestR);
		break;
	case 3: SDL_RenderCopy(setup::renderer, three, &singlesrcR, &singledestR);
		break;
	case 4: SDL_RenderCopy(setup::renderer, four, &singlesrcR, &singledestR);
		break;
	case 5: SDL_RenderCopy(setup::renderer, five, &singlesrcR, &singledestR);
		break;
	case 6: SDL_RenderCopy(setup::renderer, six, &singlesrcR, &singledestR);
		break;
	case 7: SDL_RenderCopy(setup::renderer, seven, &singlesrcR, &singledestR);
		break;
	case 8: SDL_RenderCopy(setup::renderer, eight, &singlesrcR, &singledestR);
		break;
	case 9: SDL_RenderCopy(setup::renderer, nine, &singlesrcR, &singledestR);
		break;
	default:
		break;
	}
	switch (decN) {
	case 0: SDL_RenderCopy(setup::renderer, zero, &decsrcR, &decdestR);
		break;
	case 1: SDL_RenderCopy(setup::renderer, one, &decsrcR, &decdestR);
		break;
	case 2: SDL_RenderCopy(setup::renderer, two, &decsrcR, &decdestR);
		break;
	case 3: SDL_RenderCopy(setup::renderer, three, &decsrcR, &decdestR);
		break;
	case 4: SDL_RenderCopy(setup::renderer, four, &decsrcR, &decdestR);
		break;
	case 5: SDL_RenderCopy(setup::renderer, five, &decsrcR, &decdestR);
		break;
	case 6: SDL_RenderCopy(setup::renderer, six, &decsrcR, &decdestR);
		break;
	case 7: SDL_RenderCopy(setup::renderer, seven, &decsrcR, &decdestR);
		break;
	case 8: SDL_RenderCopy(setup::renderer, eight, &decsrcR, &decdestR);
		break;
	case 9: SDL_RenderCopy(setup::renderer, nine, &decsrcR, &decdestR);
		break;
	default:
		break;
	}
}
//collision detection betweem obstacles and player
int level::isCollided() {
	gndLvl = 0;
	unsigned int size = Collision.size();
	if (size > 8) {
		for (unsigned int i = 0; i < size; i++) {
			if (Collision[i] != 0) {
				if (Obstacles[i].x_Pos <=463 && Obstacles[i].x_Pos >= 342) {
					colType = Obstacles[i+1].type;
					switch (colType) {
					case 0: gndLvl = 0;
						break;
					case 1: gndLvl = 1;
						break;
					case 2: if (Obstacles[i+1].x_Pos <= 480) { gndLvl = 2; }else { gndLvl = 1; }	  
						break;
					default:
						break;
					}
				}
			}
		}	
	}
	return gndLvl;
}


