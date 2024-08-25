#ifndef ASM_SRC_ENGINE_FILEIO_SAVEFILEMANAGER_H_
#define ASM_SRC_ENGINE_FILEIO_SAVEFILEMANAGER_H_

class SaveFileManager {
 public:
	static bool saveGame();
	static bool loadGame();

	static bool hasSaveFile();
};

#endif //ASM_SRC_ENGINE_FILEIO_SAVEFILEMANAGER_H_
