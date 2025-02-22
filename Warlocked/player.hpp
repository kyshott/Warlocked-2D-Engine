#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <vector>
#include "entity.hpp"

class Player : public Entity {
public:

    std::vector<SDL_Scancode> keyStack;

    Player(int x, int y, int w, int h, SDL_Renderer* renderer, std::string folderpath) : Entity(x, y, w, h, renderer, folderpath) {};
    void handleEvent(const SDL_Event& e);
};

#endif
