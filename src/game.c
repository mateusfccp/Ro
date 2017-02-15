#include "game.h"

Game* Game_New (const char* name, const char* version, Uint32 subsystems) {
	Game* game = (Game*) malloc(sizeof(Game));
	game->Name = name;
	game->Version = version;
	game->Subsystems = subsystems;
	game->Status = GAME_UNDEFINED;
	game->Renderer = (SDL_Renderer*) NULL;
	game->Scene = (Scene*) NULL;
	return game;
}

void Game_Start (Game* game, Scene* scene) {
	Game_PushScene(game, scene);
	game->Scene->start(game->Scene);
	game->Status = GAME_RUNNING;
}

void Game_PushScene (Game* game, Scene* scene) {
	Scene* actual = game->Scene;
	game->Scene = scene;
	scene->previous = actual;
}

void Game_PullScene (Game* game) {
	Scene* actual = game->Scene;
	game->Scene = actual->previous;
	free(actual);
}
