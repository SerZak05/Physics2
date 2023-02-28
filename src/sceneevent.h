#pragma once
#include "event.h"
#include "uielem.h"


class SceneEvent : public Event {
public:
	SceneEvent(UIElem* newScene);
	UIElem* getScene() const;

private:
	UIElem* mScene;
};