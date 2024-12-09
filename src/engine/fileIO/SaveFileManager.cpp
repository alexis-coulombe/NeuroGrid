#include "SaveFileManager.h"
#include "../Utils.h"
#include <filesystem>
#include <string>
#include <iostream>

std::string getSaveFilePath();

bool SaveFileManager::saveGame(Mission *mission) {
	std::string filename = getSaveFilePath() + "savegame.sav";
	std::fstream file(filename, std::ios::in | std::ios::out | std::ios::binary);

	checkSaveFile(&file);

	for(size_t i = 0; i < mission->getNano(Mission::NANO1)->code->getLines()->size(); i++) {
		saveData.missionSaveData[mission->ID].nano1Content[i] = mission->getNano(Mission::NANO1)->code->getLines()->at(i);
	}

	for(size_t i = 0; i < mission->getNano(Mission::NANO2)->code->getLines()->size(); i++) {
		saveData.missionSaveData[mission->ID].nano2Content[i] = mission->getNano(Mission::NANO2)->code->getLines()->at(i);
	}

	for(size_t i = 0; i < mission->getNano(Mission::NANO3)->code->getLines()->size(); i++) {
		saveData.missionSaveData[mission->ID].nano3Content[i] = mission->getNano(Mission::NANO3)->code->getLines()->at(i);
	}

	writeSaveData(&file, &saveData);
	return true;
}

bool SaveFileManager::loadGame() {
	std::string filename = getSaveFilePath() + "savegame.sav";
	std::fstream file(filename, std::ios::in | std::ios::out | std::ios::binary);

	checkSaveFile(&file);

	readSaveData(&file, &saveData);
	std::cout << "Save file version: " << (uint8_t)saveData.version << std::endl;

	if (saveData.version != SAVE_FILE_VERSION) {
		std::cout << "Save file version mismatch!" << std::endl;
		//TODO: handle futur versions
		exit(1);
	}

	//TODO: load game
	return true;
}

void SaveFileManager::checkSaveFile(std::fstream *file) {
	std::string filename = getSaveFilePath() + "savegame.sav";

	if (!file->good()) {
		std::cout << "Save file does not exist, creating a new one." << std::endl;
		std::filesystem::path savePath = getSaveFilePath();
		std::filesystem::create_directories(savePath);

		file->open(filename, std::ios::out | std::ios::binary);
		saveData = {0};
		saveData.version = SAVE_FILE_VERSION;
		writeSaveData(file, &saveData);
		file->close();
		firstPlay = true;
	}
}

void SaveFileManager::readSaveData(std::fstream *file, SaveFileManager::SaveData *saveData) {
	file->read(reinterpret_cast<char *>(saveData), sizeof(*saveData));
}

void SaveFileManager::writeSaveData(std::fstream *file, SaveFileManager::SaveData *saveData) {
	file->write(reinterpret_cast<const char*>(&saveData->version), sizeof(saveData->version));

	for (int i = 0; i < MAX_MISSIONS; ++i) {
		const MissionSaveData& mission = saveData->missionSaveData[i];
		for (int j = 0; j < MAX_TEXTAREA_LINES; ++j) {
			// Write nano1Content
			size_t length = mission.nano1Content[j].size();
			file->write(reinterpret_cast<const char*>(&length), sizeof(length));
			file->write(mission.nano1Content[j].data(), length);

			// Write nano2Content
			length = mission.nano2Content[j].size();
			file->write(reinterpret_cast<const char*>(&length), sizeof(length));
			file->write(mission.nano2Content[j].data(), length);

			// Write nano3Content
			length = mission.nano3Content[j].size();
			file->write(reinterpret_cast<const char*>(&length), sizeof(length));
			file->write(mission.nano3Content[j].data(), length);
		}
	}

	file->close();
}

std::string getSaveFilePath() {
	std::string filename = UNKNOWN_SAVE_FILE_PATH;

	switch (Utils::getPlatform()) {
		case Utils::PLATFORM::LINUX: {
			filename = LINUX_SAVE_FILE_PATH;
			break;
		}
		case Utils::PLATFORM::WINDOWS: {
			filename = WINDOWS_SAVE_FILE_PATH;
			break;
		}
		case Utils::PLATFORM::MACOS: {
			filename = MACOS_SAVE_FILE_PATH;
			break;
		}
		default:
		case Utils::PLATFORM::UNKNOWN: {
			filename = UNKNOWN_SAVE_FILE_PATH;
			break;
		}
	}

	return filename;
}