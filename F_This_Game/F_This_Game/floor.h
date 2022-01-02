
#pragma once
#include "setup.h"
#include "obstacle.h"
#include "textures.h"
#include <vector>
#include <iostream>
using namespace std;

class bottom {
public:
	bottom();
	~bottom(){}
	vector<obstacle> Floor;
	void fillVector(vector<obstacle>&);
	void update();
	void render();


private:
	int xpos = 0;
	int cnt = 0;
	SDL_Rect src, dest;
	SDL_Texture* block;
};