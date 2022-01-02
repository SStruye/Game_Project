#include "level.h"
#include "obstacle.h"
#include "textures.h"
#include <vector>
#include <iostream>
using namespace std;




level::level() {
	fillVector(Obstacles, lvl[0]);
};

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
		fillVector(Obstacles, lvl[iterator]);
		Collision.push_back(lvl[iterator]);
		iterator++;
		cnt = 0;
	}
	if (iterator == 74) {
		finished = true;
	}
	cout << "score: " << iterator << endl;
}

bool level::reset() {
	return finished;
}

void level::render() {
	unsigned int size = Obstacles.size();
	for (unsigned int i = 0; i < size; i++) {
		Obstacles[i].render();
	}
}

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

