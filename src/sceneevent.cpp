#include "sceneevent.h"

SceneEvent::SceneEvent(UIElem* newScene) : Event(SCENE_EVENT), mScene(newScene) {}

UIElem* SceneEvent::getScene() const {
	return mScene;
}
