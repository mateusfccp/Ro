#ifndef RO_SCENE
#define RO_SCENE

#include <SDL2/SDL.h>

// This struct defines how a Scene will work
typedef struct _Scene {
	// The functions associated with the Scene
	void (*start)(struct _Scene* self);
	void (*logic_update)(struct _Scene* self);
	void (* events_update)(struct _Scene* self);
	void (* render)(struct _Scene* self);
	void (* exit)(struct _Scene* self);

	// The Scene struct has a link with the previous scene, so it can be pushed/pulled
	struct _Scene* previous;
} Scene;

Scene* Scene_New(void (*start)(struct _Scene* self), void (*logic_update)(struct _Scene* self), void (*events_update)(struct _Scene* self), void (*render)(struct _Scene* self), void (*exit)(struct _Scene* self));

#endif
