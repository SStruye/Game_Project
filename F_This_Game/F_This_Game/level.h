#pragma once
#include "setup.h"
#include "textures.h"
#include "obstacle.h"
#include <vector>
#include <iostream>
using namespace std;

class level {
public:
	level();
	~level(){}
	vector<obstacle> Obstacles;
	vector<int> Collision = { };
	void fillVector(vector<obstacle>&, int type);
	void update();
	void render();
	bool reset();
	int isCollided();
	int getType() { return colType; }
	
private:
	int lvl[64] = { 0,0,0,0,0,0,0,1,2,0,0,0,0,2,1,0,0,0,0,2,1,1,1,0,0,0,0,1,2,2,1,1,1,2,0,0,0,0,0,1,0,0,0,0,1,2,2,1,0,0,0,0,0,1,1,0,0,0,0,1,2,0,0,4 };
	int lvlSize = sizeof(lvl) / sizeof(lvl[0]);
	bool finished = false;
	int colType = 0;
	int iterator = 0;
	int cnt = 0;
	int type = 0;
	int gndLvl = 0;
	int score = 0;

	SDL_Texture* zero;
	SDL_Texture* one;
	SDL_Texture* two;
	SDL_Texture* three;
	SDL_Texture* four;
	SDL_Texture* five;
	SDL_Texture* six;
	SDL_Texture* seven;
	SDL_Texture* eight;
	SDL_Texture* nine;

	SDL_Rect singlesrcR, singledestR;
	SDL_Rect decsrcR, decdestR;
};