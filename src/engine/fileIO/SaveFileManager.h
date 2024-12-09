#ifndef ASM_SRC_ENGINE_FILEIO_SAVEFILEMANAGER_H_
#define ASM_SRC_ENGINE_FILEIO_SAVEFILEMANAGER_H_

#include <cstdint>
#include <fstream>
#include "../../Config.h"
#include "../../game/logic/Nano.h"
#include "../../game/mission/Mission.h"

class SaveFileManager {
 public:
	typedef struct {
		std::string nano1Content[MAX_TEXTAREA_LINES];
		std::string nano2Content[MAX_TEXTAREA_LINES];
		std::string nano3Content[MAX_TEXTAREA_LINES];
	} MissionSaveData;

	typedef struct {
		uint8_t version;
		MissionSaveData missionSaveData[MAX_MISSIONS];
	} SaveData;

	bool firstPlay = false;

	bool saveGame(Mission *mission);
	bool loadGame();
 private:
	SaveData saveData;

	void checkSaveFile(std::fstream *file);
	void readSaveData(std::fstream *file, SaveData *saveData);
	void writeSaveData(std::fstream *file, SaveData *saveData);
};

#endif //ASM_SRC_ENGINE_FILEIO_SAVEFILEMANAGER_H_
