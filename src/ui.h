#pragma once
#include <SFML/Graphics.hpp>
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

	EventLoop<sf::Event::EventType, sf::Event> userEventLoop;
	EventLoop<EventType, Event> eventLoop;
private:
	UIElem* currScene = nullptr;

	class ExitTrigger : public Subscriber<sf::Event::EventType, sf::Event> {
	public:
		ExitTrigger(UI&);
		void processEvent(const sf::Event*);
		std::list<sf::Event::EventType> acceptTypes() const;
	private:
		UI& mUI;
	} exitTrigger;
};