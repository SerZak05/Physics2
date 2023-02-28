#pragma once
#include<functional>
#include "ui.h"


class KeyBind : public Subscriber<sf::Event::EventType, sf::Event> {
public:
	KeyBind(UI&, char keyBind, std::function<void(char)> callback);
	void processEvent(const sf::Event*);
	std::list<sf::Event::EventType> acceptTypes() const;
private:
	char mKeyBind;
	std::function<void(char)> mCallBack;
};

