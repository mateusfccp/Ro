#include "engine.h"
#define $(D) ((data_s*) self->data)->D

typedef struct {
	int value;
} data_s;

void sstart(Scene* self) {
	Engine_LogInfo("Starting Scene!");
	self->data = (data_s*) malloc(sizeof(data_s));
	((data_s*) self->data)->value = 1;
}

void sexit(Scene* self) {
	Engine_LogInfo("Exiting Scene!");
}

void slogic_update(Scene* self) {
	printf("logic_update! data→value = %d", ((data_s*) self->data)->value);
	printf("%d", $(value));
}

void sevents_update(Scene* self) {
	//Engine_LogInfo("events_update!");
}

void srender(Scene* self) {
	//Engine_LogInfo("rendering!");
}

Scene* test_scene_new() {
	return Scene_New(sstart, slogic_update, sevents_update, srender, sexit);
}
