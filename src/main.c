#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "engine.h"
#include "test_scene.h"

int main (int argc, char** argv) {

	Game* game = Game_New(
		"Um RPG Louco",        // Game Name
		"0.0.1",               // Game Version
		SDL_INIT_EVERYTHING    //Subsystems
	);

	SDL_Event e;
	Engine_Initialize (game);
	Game_Start(game, test_scene_new());

	//Here starts the main loop
	while (game->Status != GAME_QUITTING) {
		
		// The main loop will automatically quit when no scene can be found.
		if(game->Scene == NULL) {
			Engine_LogInfo("The engine has no scene. Exiting game.");
			game->Status = GAME_QUITTING;
			continue;
		}

		game->Scene->events_update(game->Scene);
		game->Scene->logic_update(game->Scene);
		game->Scene->render(game->Scene);
		/*
		SDL_RenderClear(game->Renderer);
		SDL_RenderPresent(game->Renderer);

		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) {
			SDL_Log ("program-quit");
			break;
		}
		*/
		Game_PullScene(game);
	}
	Engine_Quit(game);
	return 0;
}
