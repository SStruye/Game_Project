#define _CRTDBG_MAP_ALLOC

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

#include "recourses.h"
#include "setup.h"
#include <stdlib.h>
#include <crtdbg.h>

setup *Setup = nullptr;

int main(int argc, char* args[]) {
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	
	Setup = new setup();
	//initiale game
	Setup->init("F*ck This Game", 1024, 640);
	
	while (Setup->running()) {
			frameStart = SDL_GetTicks();
			Setup->EventHandler();
			Setup->update();
			Setup->render();
			frameTime = SDL_GetTicks() - frameStart;
			if (frameDelay > frameTime) {
				SDL_Delay(frameDelay - frameTime);
			}
	}
	Setup->clean();
	_CrtDumpMemoryLeaks();
	return 0;
}