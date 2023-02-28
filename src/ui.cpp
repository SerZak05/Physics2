#include "ui.h"
#include "keybind.h"
#include "sceneevent.h"
#include "appcontroller.h"

bool UI::init() {
	bool success = true;
	//mSceneEventLoop.subscribe(this, SCENE_EVENT);
	currScene = new UIElem(this);	
	return success;
}

void UI::update() {
	sf::RenderWindow& window = AppController::getInstance()->window;
	sf::Event e;
	while (window.pollEvent(e)) {
		sf::Event* newEvent = new sf::Event(e);
		userEventLoop.pushEvent(newEvent);
	}
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