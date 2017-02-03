#ifndef ENGINE_GAME
#define ENGINE_GAME

#include <SDL2/SDL.h>

typedef struct {
	// Constant Variables, they are going to be hard-coded
	const char* Name;
	const char* Version;
	int Subsystems;

	// Window variable, for auto-desinitialization
	SDL_Window* window;

	// Variables that are going to change through game
	void* Scene;
} Game;

Game* Engine_NewGame (const char*, const char*, int);
void Engine_Initialize (Game*);
void Engine_Quit (Game* game);
void Engine_LogInfo(const char*);
void Engine_LogError (const char*);

#endif
