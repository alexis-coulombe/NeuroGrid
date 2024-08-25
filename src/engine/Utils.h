#ifndef ASM_SRC_ENGINE_UTILS_H_
#define ASM_SRC_ENGINE_UTILS_H_

class Utils {
 public:
	enum PLATFORM {
		LINUX,
		WINDOWS,
		MACOS,
		UNKNOWN
	};

	static PLATFORM getPlatform();
};

#endif //ASM_SRC_ENGINE_UTILS_H_