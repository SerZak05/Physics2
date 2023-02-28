#include "uielem.h"

#include "merrors.h"

UIElem::UIElem(UI* ui) : mUI(ui) {}

UIElem::~UIElem() {
	while (!children.empty()) {
		delete (*children.rbegin());
		children.pop_back();
	}
}

void UIElem::_processEvent(const SDL_Event*) {}

void UIElem::processEvent(const SDL_Event* ev) {
	for (UIElem* child : children) {
		child->processEvent(ev);
	}
	_processEvent(ev);
}

std::list<SDL_EventType> UIElem::acceptTypes() const {
	return std::list<SDL_EventType>();
}

void UIElem::update() {
	for (UIElem* child : children) {
		child->update();
	}
}

void UIElem::draw(Drawer* dr) const {
	for (UIElem* child : children) {
		child->draw(dr);
	}
}
