#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>
#include <string>

enum Direction { NONE, UP, DOWN, LEFT, RIGHT };

class Entity {
public:

    std::vector<std::string> textures;
    SDL_Texture* sprites[5];
    SDL_Rect rect;
    Direction dir;

    Entity(int x, int y, int w, int h, SDL_Renderer* renderer, std::string folderpath);
    void updateTexture(SDL_Renderer* renderer);
    void update(SDL_Renderer* renderer);
    void readinTextures(std::vector<std::string> textures, std::string folderpath);
    void initTexture(SDL_Renderer* renderer);

};

#endif