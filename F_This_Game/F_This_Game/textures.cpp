#include "textures.h"

//texture loader
SDL_Texture* textures::LoadTexture(const char* file) {
	SDL_Surface* tmpSur = IMG_Load(file);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(setup::renderer, tmpSur);
	SDL_FreeSurface(tmpSur);
	return texture;
}
//texture renderer
void textures::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(setup::renderer, texture, &src, &dest);
}