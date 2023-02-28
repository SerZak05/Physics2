#include "ui.h"
#include "keybind.h"
#include "sceneevent.h"

bool UI::init() {
	bool success = true;
	//mSceneEventLoop.subscribe(this, SCENE_EVENT);
	currScene = new UIElem(this);	
	return success;
}

void UI::update() {
	SDL_Event* e = new SDL_Event();
	while (SDL_PollEvent(e)) {
		userEventLoop.pushEvent(e);
		e = new SDL_Event();
	}
	delete e;
	while (userEventLoop.pullEvent());
	while (eventLoop.pullEvent());
	if (currScene != nullptr)
		currScene->update();
}

void UI::cleanup() {
	delete currScene;
}

std::list<EventType> UI::acceptTypes() const {
	return {SCENE_EVENT};
}

void UI::processEvent(const Event* ev) {
	const SceneEvent* sceneEv = static_cast<const SceneEvent*>(ev);
	delete currScene;
	currScene = sceneEv->getScene();
}

UI::UI() : exitTrigger(*this) {}