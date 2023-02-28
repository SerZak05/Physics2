#include "appcontroller.h"
#include <SDL.h>
#include <SDL_image.h>
// #include "common.h"
#include "merrors.h"
#include "event.h"

AppController::AppController() {
	
}

AppController::~AppController() {
}

bool AppController::init() {
	mErrorLog::stream << "I`m working." << std::endl;
	bool success = true;
	if (!mErrorLog::maccept(!SDL_Init(SDL_INIT_EVERYTHING), "Failed to init SDL!", success)) {
		mErrorLog::stream << SDL_GetError() << std::endl;
	}
	else {
		if (!mErrorLog::maccept(IMG_Init(IMG_INIT_PNG), "Failed to init IMG!", success)) {
			mErrorLog::stream << IMG_GetError() << std::endl;
		}
		mErrorLog::maccept(mUI.init(), "Failed to init UI!", success);
		mErrorLog::maccept(mDrawer.init(), "Failed to init Drawer!", success);
		// mErrorLog::maccept(mDrawer.loadTexture("circle.png"), "Failed to load image!", success);

		mUI.eventLoop.subscribe(this);
		/*if (success) {
			mGame.init(&mUI);
		}*/
	}
	return success;
}

void AppController::run() {
	Running = true;
	while (Running) {
		mUI.update();
		mField.physUpdate();
		mField.draw(&mDrawer);
		mDrawer.render();
		mErrorLog::stream << "====LOOP====" << std::endl;
	}
}

void AppController::stop() {
	Running = false;
}

void AppController::cleanup() {
	mUI.cleanup();
	mDrawer.cleanup();
	IMG_Quit();
	SDL_Quit();
}

void AppController::processEvent(const Event*) {
	stop();
}

std::list<EventType> AppController::acceptTypes() const {
	return { EXIT_EVENT };
}
