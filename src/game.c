#include <stdlib.h>
#include "game.h"

Game* Engine_NewGame (const char* name, const char* version, int subsystems) {
	Game* game = (Game*) malloc(sizeof(Game));
	game->Name = name;
	game->Version = version;
	game->Subsystems = subsystems;
	return game;
}

void Engine_Initialize (Game* game) {
	// Try to initialize SDL
	if (SDL_Init(game->Subsystems) != 0) {
		Engine_LogError("Could not initialize SDL!");
		exit(1);
	}

	// Crete a new main window
	game->window = SDL_CreateWindow(
		game->Name,                  // window title
		SDL_WINDOWPOS_CENTERED,      // initial x position
		SDL_WINDOWPOS_CENTERED,      // initial y position
		640,                         // width, in pixels
		480,                         // height, in pixels
		SDL_WINDOW_OPENGL            // flags - see below
	);

	// Verify if Windows has been properly created
	if (game->window == NULL) {
		Engine_LogError("Could not create window!");
	}
}

void Engine_Quit (Game* game) {
	if (game->window != NULL) SDL_DestroyWindow(game->window);
	SDL_Quit();
	free(game);
}

void Engine_LogInfo (const char* message) {
	SDL_Log("Error: %s\n\t%s\n", message, SDL_GetError());
}

void Engine_LogError (const char* message) {
	SDL_LogError("Error: %s\n\t%s\n", message, SDL_GetError());
}
