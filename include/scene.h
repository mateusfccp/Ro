#ifndef RO_SCENE
#define RO_SCENE

#include <SDL2/SDL.h>

// This struct defines how a Scene will work
typedef struct _Scene {

	// The functions associated with the Scene
	void (*start)(void);
	void (*logic_update)(void);
	void (*events_update)(SDL_Event);
	void (*render)(void);
	void (*exit)(void);

	// The Scene struct has a link with the previous scene, so it can be pushed/pulled
	struct _Scene* previous;
} Scene;

#endif
