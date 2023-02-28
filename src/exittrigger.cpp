#include "ui.h"

UI::ExitTrigger::ExitTrigger(UI& ui) : mUI(ui) {
	ui.userEventLoop.subscribe(this);
}

void UI::ExitTrigger::processEvent(const SDL_Event*) {
	mUI.eventLoop.pushEvent(new Event(EXIT_EVENT));
}

std::list<SDL_EventType> UI::ExitTrigger::acceptTypes() const {
	return {SDL_QUIT};
}
