#include "entity.hpp"
#include "textureloader.hpp"
#include <iostream>
#include <filesystem>

//Define player rectangle starting position and width/height
Entity::Entity(int x, int y, int w, int h, SDL_Renderer* renderer, std::string folderpath) {
	rect = { x, y, w, h };
	dir = NONE;
	readinTextures(textures, folderpath);
	initTexture(renderer);
	SDL_RenderCopy(renderer, sprites[DOWN], NULL, &rect);
}

//Update player position based on key held
void Entity::update(SDL_Renderer* renderer) {

	//Window boundary detection... 100% temporary in this case will be changed later
	if (rect.x < 0) rect.x = 0;
	if (rect.y < 0) rect.y = 0;
	if (rect.x + 50 > 1000) rect.x = 1000 - 50;
	if (rect.y + 50 > 1000) rect.y = 1000 - 50;

	switch (dir)
	{
	case DOWN:
		rect.y += 10; break;
	case UP:
		rect.y -= 10; break;
	case LEFT:
		rect.x -= 10; break;
	case RIGHT:
		rect.x += 10; break;
	case NONE:
		break;
	}
}

void Entity::readinTextures(std::vector<std::string> textures, std::string folderpath) {

	for (const auto& file : std::filesystem::directory_iterator(folderpath)) {
		textures.push_back(file.path().string());
	}
}

//Loads / updates the player texture based on the direction enumeration
void Entity::updateTexture(SDL_Renderer* renderer) {
	switch (dir)
	{
	case DOWN:
		SDL_RenderCopy(renderer, sprites[DOWN], NULL, &rect); break;
	case UP:
		SDL_RenderCopy(renderer, sprites[DOWN], NULL, &rect); break;
	case LEFT:
		SDL_RenderCopy(renderer, sprites[DOWN], NULL, &rect); break;
	case RIGHT:
		SDL_RenderCopy(renderer, sprites[DOWN], NULL, &rect); break;
	case NONE:
		SDL_RenderCopy(renderer, sprites[DOWN], NULL, &rect); break;
	}
}

void Entity::initTexture(SDL_Renderer* renderer) {

	for (int i = 1; i < 5; i++) {
		if (i == 1) {
			sprites[UP] = loadTexture(textures[i], renderer);
		}
		if (i == 2) {
			sprites[DOWN] = loadTexture(textures[i], renderer);
		}
		if (i == 3) {
			sprites[LEFT] = loadTexture(textures[i], renderer);
		}
		if (i == 4) {
			sprites[RIGHT] = loadTexture(textures[i], renderer);
		}
	}

	//SDL_SetTextureBlendMode(sprites[UP], SDL_BLENDMODE_BLEND);
	//SDL_SetTextureBlendMode(sprites[DOWN], SDL_BLENDMODE_BLEND);

	if (!sprites[UP] || !sprites[DOWN] || !sprites[LEFT] || !sprites[RIGHT]) {
		std::cout << "Failed to load player textures! SDL_Error: " << SDL_GetError() << std::endl;
	}

}