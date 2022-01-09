#include "floor.h"


bottom::bottom() {
	fillVector(Floor);
}
//create moving floor created with blocks using vector
void bottom::fillVector(vector<obstacle>&newAdd) {
	obstacle newObstacle(3, 1024, 576);
	newAdd.push_back(newObstacle);
}
//function to update the floor every frame
void bottom::update() {
	unsigned int size = Floor.size();
	//moves floor to the left
	for (unsigned int i = 0; i < size; i++) {
		Floor[i].move();
		Floor[i].update();
	}
	//erases blocks if there out of frame
	if (Floor[0].x_Pos <= -64) {
		Floor.erase(Floor.begin());
		Floor.shrink_to_fit();
	}
	cnt++;
	//every 16 frames add a new block 
	if (cnt == 16) {
		fillVector(Floor);
		cnt = 0;
	}
}
//floor renderer
void bottom::render() {
	unsigned int size = Floor.size();
	for (unsigned int i = 0; i < size; i++) {
		Floor[i].render();
	}
}

