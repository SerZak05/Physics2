#pragma once
#include "drawer.h"
#include "ui.h"
#include "field.h"

class UI;

class AppController : Subscriber<EventType, Event> {
public:
	AppController();
	~AppController();

	bool init();

	void run();
	void stop();

	void cleanup();

	void processEvent(const Event*);
	std::list<EventType> acceptTypes() const;
private:
	bool Running = false;

	UI mUI;
	Field mField;
	Drawer mDrawer;
};