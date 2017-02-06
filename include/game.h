#ifndef RO_GAME
#define RO_GAME

#include <SDL2/SDL.h>
#include "scene.h"

typedef enum {
	GAME_UNDEFINED,
	GAME_RUNNING,
	GAME_PAUSED,
	GAME_QUITTING
} GameStatus;

typedef struct {
	// Constant Variables, they are going to be hard-coded
	const char* Name;
	const char* Version;
	Uint32 Subsystems;

	// Main window variable, for auto-desinitialization
	SDL_Window* Window;

	//Main renderer variable, for auto-desinitialization
	SDL_Renderer* Renderer;

	// Variables that are going to change through game
	Scene* Scene;

	// The game status variable manages the game status. Whooa! Things like running, paused, quitting.
	GameStatus Status;
} Game;

Game* Game_New (const char*, const char*, Uint32);
void Game_Start(Game*, Scene*);
void Game_PushScene (Game*, Scene*);
void Game_PullScene (Game*);

#endif
