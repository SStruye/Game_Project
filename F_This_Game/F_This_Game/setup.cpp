#include "setup.h"
#include "textures.h"
#include "background.h"
#include "player.h"
#include "obstacle.h"
#include "floor.h"
#include "level.h"

player* Player;
level* Level;
bottom* Bottom;
background* Background;
SDL_Renderer* setup::renderer = nullptr;


setup::setup() {}
setup::~setup() {}

void setup::init(const char* title, int w_window, int h_window) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w_window, h_window, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_SetRenderDrawColor(renderer, NULL, NULL, NULL, NULL);
		isRunning = true;
	}
	else {
		isRunning = false;
	}
	Level = new level;
	Player = new player();
	Background = new background();
	Bottom = new bottom;

	startScreen = textures::LoadTexture("assets/start.png");
	src.x = src.y = 0;
	src.w = 238;
	dest.w = 476;
	src.h = 16;
	dest.h = 32;
	dest.x = 262;
	dest.y = 300;
}

void setup::EventHandler() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_SPACE:
			Player->jump();	
			start = true;
			break;
		case SDLK_ESCAPE:
			isRunning = false;
			break;
		default:
			break;
		}
		break;
	}
}

void setup::update(){
	Player->update();
	if (start) {
		Bottom->update();
		Level->update();
		Player->collision(Level->isCollided());
		reset(Player->reset(),Level->reset());
	}
}

void setup::render(){
	SDL_RenderClear(renderer);	
	Background->drawBackground();
	if (!start) {
		textures::Draw(startScreen, src, dest);
	}
	
	Bottom->render();
	Level->render();
	Player->render();
	SDL_RenderPresent(renderer);
}

void setup::clean(){
	delete Player;
	delete Level;
	delete Bottom;
	delete Background;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void setup::reset(bool isDead, bool isFinished){
	if (isDead || isFinished){
		SDL_Delay(200);
		delete Level;
		delete Bottom;
		Level = new level;
		Bottom = new bottom;
		start = false;
	}
}
