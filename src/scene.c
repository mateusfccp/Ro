#include "scene.h"

Scene* Scene_New(void (*start)(struct _Scene* self),
				 void (*logic_update)(struct _Scene* self),
				 void (*events_update)(struct _Scene* self),
				 void (*render)(struct _Scene* self),
				 void (*exit)(struct _Scene* self)) {
	Scene* scene = (Scene*) malloc(sizeof(Scene));
	scene->start = start;
	scene->logic_update = logic_update;
	scene->events_update = events_update;
	scene->render = render;
	scene->exit = exit;
	scene->previous = (Scene*) NULL;
	scene->data = (void*) NULL;
	return scene;
}
