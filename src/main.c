#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "game.h"

int main (int argc, char** argv) {
	Game* game = Engine_NewGame(
		"Um RPG Louco",        // Game Name
		"0.0.1",               // Game Version
		SDL_INIT_EVERYTHING    //Subsystems
	);
	SDL_Event e;
	Engine_Initialize (game);
	//Here starts the main loop
	while (1) {
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) {
			SDL_Log ("program-quit");
			break;
		}
	}
	Engine_Quit(game);
	return 0;
}
