#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>
#include <string>

enum Direction { NONE, UP, DOWN, LEFT, RIGHT };

class Entity {
public:

    Direction dir;

    int spriteWidth;
    int spriteHeight;
    int spriteindex;

    SDL_Rect rect;
    SDL_Rect srcRect;

    std::string path;

    SDL_Texture* texture;

    Entity(int x, int y, int w, int h, SDL_Renderer* renderer, std::string givenpath);
    void renderSprite(SDL_Renderer* renderer);
    void update(SDL_Renderer* renderer);
    void initTexture(SDL_Renderer* renderer);

};

#endif