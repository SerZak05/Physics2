#pragma once
#include<functional>
#include "ui.h"


class KeyBind : public Subscriber<SDL_EventType, SDL_Event> {
public:
	KeyBind(UI&, char keyBind, std::function<void(char)> callback);
	void processEvent(const SDL_Event*);
	std::list<SDL_EventType> acceptTypes() const;
private:
	char mKeyBind;
	std::function<void(char)> mCallBack;
};

