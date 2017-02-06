#include <stdlib.h>
#include "engine.h"

void Engine_Initialize (Game* game) {
	// Try to initialize SDL
	if (SDL_Init(game->Subsystems) != 0) {
		Engine_LogError("Could not initialize SDL!");
		exit(1);
	}

	// Crete a new main windows
	game->Window = SDL_CreateWindow(
		game->Name,                  // window title
		SDL_WINDOWPOS_CENTERED,      // initial x position
		SDL_WINDOWPOS_CENTERED,      // initial y position
		640,                         // width, in pixels
		480,                         // height, in pixels
		NULL                // flags - see below
	);

	// Verify if Windows has been properly created
	if (game->Window == NULL) {
		Engine_LogError("Could not create window!");
		Engine_Quit(game);
		exit(1);
	}

	game->Renderer = SDL_CreateRenderer(
		game->Window,                                           // the window where rendering is displayed
		-1,                                                     // use the first available device
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC    // use a hardware accelerated renderer with vsync enabled
	);

	if (game->Renderer == NULL) {
		Engine_LogError("Could not create renderer!");
		Engine_Quit(game);
		exit(1);
	}
}

void Engine_Quit (Game* game) {
	if (game->Renderer != NULL) SDL_DestroyRenderer(game->Renderer);
	if (game->Window != NULL) SDL_DestroyWindow(game->Window);
	SDL_Quit();
	free(game);
}

void Engine_LogInfo (const char* message) {
	SDL_Log("Error: %s\n\t%s\n", message, SDL_GetError());
}

void Engine_LogError (const char* message) {
	SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Error: %s\n\t%s\n", message, SDL_GetError());
}
