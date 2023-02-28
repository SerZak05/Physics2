#pragma once
#include <fstream>

namespace mErrorLog {
	void init();

	static void error_message(const std::string message);

	void cleanup();

	bool maccept(bool res, std::string message, bool& flag);
	extern std::fstream stream;
}