#include "Utils.h"

Utils::PLATFORM Utils::getPlatform() {
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
		return WINDOWS;
	#elif __APPLE__
		return MACOS;
	#elif __linux__
		return LINUX;
	#else
		return UNKNOWN;
	#endif
}