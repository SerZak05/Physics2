#include "merrors.h"

std::fstream mErrorLog::stream;

void mErrorLog::init() {
	stream.open("errors.txt", std::fstream::out);
	//outfile << "!!!" << std::endl;
}

void mErrorLog::error_message(const std::string message) {
	stream << message << std::endl;
}

void mErrorLog::cleanup() {
	stream.close();
}

bool mErrorLog::maccept(bool res, std::string message, bool& flag) {
	if (!res) {
		error_message(message);
		flag = false;
		return false;
	}
	return true;
}
