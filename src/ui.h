#pragma once
#include <SDL.h>
#include <list>
#include "eventloop.h"
#include "uielem.h"
#include "event.h"

class UIElem;

class UI : Subscriber<EventType, Event> {
public:
	UI();

	bool init();
	void update();
	void cleanup();

	void processEvent(const Event*);
	std::list<EventType> acceptTypes() const;

	EventLoop<SDL_EventType, SDL_Event> userEventLoop;
	EventLoop<EventType, Event> eventLoop;
private:
	UIElem* currScene = nullptr;

	class ExitTrigger : public Subscriber<SDL_EventType, SDL_Event> {
	public:
		ExitTrigger(UI&);
		void processEvent(const SDL_Event*);
		std::list<SDL_EventType> acceptTypes() const;
	private:
		UI& mUI;
	} exitTrigger;
};