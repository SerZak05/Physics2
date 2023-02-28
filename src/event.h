#pragma once

enum EventType {
	SCENE_EVENT,
	EXIT_EVENT,
	EVENT_TYPE_TOTAL
};


class Event {
public:
	Event(EventType t);
	virtual ~Event();

	EventType type;
};

