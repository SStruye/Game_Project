#include "recourses.h"
#include "setup.h"
#include <stdlib.h>


setup *Setup = nullptr;

int main(int argc, char* args[]) {
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	Setup = new setup();
	Setup->init("F*ck This Game", 1024, 640);
	
	while (Setup->running()) {
		frameStart = SDL_GetTicks();
		Setup->EventHandler();
		Setup->update();
		Setup->render();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime){
			SDL_Delay(frameDelay - frameTime);
		}
	}
	Setup->clean();
	return 0;
}