#include "keybind.h"
#include "merrors.h"

KeyBind::KeyBind(UI& ui, char keyBind, std::function<void(char)> callback) : mKeyBind(keyBind), mCallBack(callback) {
	ui.userEventLoop.subscribe(this);
}

void KeyBind::processEvent(const SDL_Event* ev) {
	const SDL_KeyboardEvent keyboardEv = ev->key;
	mErrorLog::stream << (char)keyboardEv.keysym.sym << std::endl;
}

std::list<SDL_EventType> KeyBind::acceptTypes() const {
	return {SDL_KEYDOWN, SDL_KEYUP};
}
