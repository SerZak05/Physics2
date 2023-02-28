#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "subscriber.h"
#include "drawer.h"
#include "ui.h"

class UI;


class UIElem : public Subscriber<sf::Event::EventType, sf::Event> {
public:
	UIElem(UI*);
	virtual ~UIElem();
	void processEvent(const sf::Event*) final;
	std::list<sf::Event::EventType> acceptTypes() const;
	std::list<UIElem*> children;

	virtual void update();

	virtual void draw(Drawer*) const;
protected:
	UI* mUI;
	virtual void _processEvent(const sf::Event*);
};

