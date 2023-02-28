#pragma once
#include <SDL.h>
#include <list>
#include "subscriber.h"
#include "drawer.h"
#include "ui.h"

class UI;


class UIElem : public Subscriber<SDL_EventType, SDL_Event> {
public:
	UIElem(UI*);
	virtual ~UIElem();
	void processEvent(const SDL_Event*) final;
	std::list<SDL_EventType> acceptTypes() const;
	std::list<UIElem*> children;

	virtual void update();

	virtual void draw(Drawer*) const;
protected:
	UI* mUI;
	virtual void _processEvent(const SDL_Event*);
};

