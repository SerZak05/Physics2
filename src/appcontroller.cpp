#include "appcontroller.h"
// #include "common.h"
#include "merrors.h"
#include "event.h"

AppController* AppController::instance = nullptr;
AppController* AppController::getInstance() {
	if (instance == nullptr)
		instance = new AppController();
	return instance;
}

AppController::AppController() : window(sf::VideoMode(500, 500), "Physics 2") {
	mErrorLog::stream << "Creating app controller" << std::endl;
}

AppController::~AppController() {}

bool AppController::init() {
	mErrorLog::stream << "I`m working." << std::endl;
	bool success = true;
	mErrorLog::maccept(mUI.init(), "Failed to init UI!", success);
	mErrorLog::maccept(mDrawer.init(), "Failed to init Drawer!", success);
	// mErrorLog::maccept(mDrawer.loadTexture("circle.png"), "Failed to load image!", success);

	mUI.eventLoop.subscribe(this);
	/*if (success) {
		mGame.init(&mUI);
	}*/
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
	instance->mUI.cleanup();
	instance->mDrawer.cleanup();
	instance->window.close();

	delete instance;
}

void AppController::processEvent(const Event*) {
	stop();
}

std::list<EventType> AppController::acceptTypes() const {
	return { EXIT_EVENT };
}
