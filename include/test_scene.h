#include "scene.h"

void sstart(Scene* self) {
	Engine_LogInfo("Starting Scene!");
}

void sexit(Scene* self) {
	Engine_LogInfo("Exiting Scene!");
}

void slogic_update(Scene* self) {
	Engine_LogInfo("logic_update!");
}

void sevents_update(Scene* self) {
	Engine_LogInfo("events_update!");
}

void srender(Scene* self) {
	Engine_LogInfo("rendering!");
}

Scene* test_scene_new() {
	return Scene_New(sstart, slogic_update, sevents_update, srender, sexit);
}
