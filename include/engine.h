#ifndef RO_ENGINE
#define RO_ENGINE

#include <SDL2/SDL.h>
#include "game.h"

void Engine_Initialize (Game*);
void Engine_Quit (Game*);
void Engine_LogInfo(const char*);
void Engine_LogError (const char*);

#endif
