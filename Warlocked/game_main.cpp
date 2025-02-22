#include <SDL.h>
#include "gameloop.hpp"
#undef main

Game game;

int main() {
	
	game.gameloop();

	return 0;

}