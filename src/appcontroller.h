#pragma once
#include "drawer.h"
#include "ui.h"
#include "field.h"

class UI;

class AppController : Subscriber<EventType, Event> {
public:
	static AppController* getInstance();
	~AppController();

	bool init();

	void run();
	void stop();

	static void cleanup();

	void processEvent(const Event*);
	std::list<EventType> acceptTypes() const;

	sf::RenderWindow window;
private:
	AppController();
	static AppController* instance;

	bool Running = false;

	UI mUI;
	Field mField;
	Drawer mDrawer;
};