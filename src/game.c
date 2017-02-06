#include "game.h"

Game* Game_New (const char* name, const char* version, Uint32 subsystems) {
	Game* game = (Game*) malloc(sizeof(Game));
	game->Name = name;
	game->Version = version;
	game->Subsystems = subsystems;
	game->Status = GAME_UNDEFINED;
	return game;
}

void Game_Start (Game* game, Scene* scene) {
	game->Scene = scene;
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
