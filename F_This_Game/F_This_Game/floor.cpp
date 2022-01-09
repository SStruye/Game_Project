#include "floor.h"

bottom::bottom() {
	fillVector(Floor);
}

void bottom::fillVector(vector<obstacle>&newAdd) {
	obstacle newObstacle(3, 1024, 576);
	newAdd.push_back(newObstacle);
}
void bottom::update() {
	unsigned int size = Floor.size();
	for (unsigned int i = 0; i < size; i++) {
		Floor[i].move();
		Floor[i].update();
	}
	if (Floor[0].x_Pos <= -64) {
		Floor.erase(Floor.begin());
		Floor.shrink_to_fit();
	}
	cnt++;
	if (cnt == 16) {
		fillVector(Floor);
		cnt = 0;
	}
}

void bottom::render() {
	unsigned int size = Floor.size();
	for (unsigned int i = 0; i < size; i++) {
		Floor[i].render();
	}
}

