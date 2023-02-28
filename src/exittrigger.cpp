#include "ui.h"

UI::ExitTrigger::ExitTrigger(UI& ui) : mUI(ui) {
	ui.userEventLoop.subscribe(this);
}

void UI::ExitTrigger::processEvent(const sf::Event*) {
	mUI.eventLoop.pushEvent(new Event(EXIT_EVENT));
}

std::list<sf::Event::EventType> UI::ExitTrigger::acceptTypes() const {
	return {sf::Event::Closed};
}
