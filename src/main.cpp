#include <iostream>
#include "appcontroller.h"
#include "merrors.h"

int main(int argc, char* args[]) {
	mErrorLog::init();
	mErrorLog::stream << "message" << std::endl;
	AppController& app = *AppController::getInstance();
	if (!app.init()) {
		mErrorLog::stream << "Failed to initialize app controller!" << std::endl;
	}
	else {
		app.run();
		app.cleanup();
	}
	mErrorLog::cleanup();
	return 0;
}