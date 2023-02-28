#include "keybind.h"
#include "merrors.h"

KeyBind::KeyBind(UI& ui, char keyBind, std::function<void(char)> callback) : mKeyBind(keyBind), mCallBack(callback) {
	ui.userEventLoop.subscribe(this);
}

void KeyBind::processEvent(const sf::Event* ev) {
	mErrorLog::stream << (char)(ev->key.code + 'a') << std::endl;
}

std::list<sf::Event::EventType> KeyBind::acceptTypes() const {
	return {sf::Event::KeyPressed, sf::Event::KeyReleased};
}
