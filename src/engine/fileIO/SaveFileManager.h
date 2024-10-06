#ifndef ASM_SRC_ENGINE_FILEIO_SAVEFILEMANAGER_H_
#define ASM_SRC_ENGINE_FILEIO_SAVEFILEMANAGER_H_

#include <cstdint>
#include <fstream>
#include "../../Config.h"

class SaveFileManager {
 public:
	typedef struct {
		uint8_t missionID;
		uint8_t missionStatus;
		uint8_t nano1Content[MAX_TEXTAREA_LINES][MAX_TEXTAREA_LINE_LENGTH];
		uint8_t nano2Content[MAX_TEXTAREA_LINES][MAX_TEXTAREA_LINE_LENGTH];
		uint8_t nano3Content[MAX_TEXTAREA_LINES][MAX_TEXTAREA_LINE_LENGTH];
	} MissionSaveData;

	typedef struct {
		MissionSaveData missionSaveData[MAX_MISSIONS];
	} SaveData;

	static bool saveGame();
	static bool loadGame();

	static bool hasSaveFile();
 private:
	static uint8_t readVersion(std::fstream *file);
	static void writeVersion(std::fstream *file, uint8_t version);
	static SaveData readSaveData(std::fstream *file, SaveData *saveData);
	static void writeSaveData(std::fstream *file, SaveData *saveData);
};

#endif //ASM_SRC_ENGINE_FILEIO_SAVEFILEMANAGER_H_
