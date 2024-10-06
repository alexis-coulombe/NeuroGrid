#include "SaveFileManager.h"
#include "../Utils.h"
#include <filesystem>
#include <string>
#include <iostream>

std::string getSaveFilePath();

bool SaveFileManager::saveGame() {
	std::string filename = getSaveFilePath() + "savegame.sav";
	std::fstream file(filename, std::ios::in | std::ios::out | std::ios::binary);

	if (!file) {
		std::cout << "Save file does not exist, creating a new one." << std::endl;
		std::filesystem::path savePath = getSaveFilePath();
		std::filesystem::create_directories(savePath);

		file.open(filename, std::ios::in | std::ios::binary);
		writeVersion(&file, SAVE_FILE_VERSION);

		// Write default data
		SaveData saveData = {0};
		for(size_t i = 0; i < MAX_MISSIONS; i++) {
			writeSaveData(&file, &saveData);
		}

		file.close();
	}

	file.open(filename, std::ios::in | std::ios::out | std::ios::binary);

	uint8_t version = readVersion(&file);
	std::cout << "Save file version: " << (uint8_t)version << std::endl;

	file.close();

	return true;
}

bool SaveFileManager::loadGame() {
	return false;
}

bool SaveFileManager::hasSaveFile() {
	std::string filename = getSaveFilePath() + "savegame.sav";
	std::fstream file(filename, std::ios::in | std::ios::out | std::ios::binary);

	return file.good();
}

uint8_t SaveFileManager::readVersion(std::fstream *file) {
	uint8_t version;
	file->read(reinterpret_cast<char *>(&version), sizeof(version));
	file->seekg(sizeof(version), std::ios::beg);

	return version;
}

void SaveFileManager::writeVersion(std::fstream *file, uint8_t version) {
	file->write(reinterpret_cast<char *>(&version), sizeof(version));
	file->seekp(sizeof(version), std::ios::beg);
}

SaveFileManager::SaveData SaveFileManager::readSaveData(std::fstream *file, SaveFileManager::SaveData *saveData) {
	file->read(reinterpret_cast<char *>(saveData), sizeof(SaveFileManager::SaveData));
	file->seekg(sizeof(SaveFileManager::SaveData), std::ios::beg);

	return *saveData;
}

void SaveFileManager::writeSaveData(std::fstream *file, SaveFileManager::SaveData *saveData) {
	file->write(reinterpret_cast<char *>(saveData), sizeof(SaveFileManager::SaveData));
	file->seekp(sizeof(SaveFileManager::SaveData), std::ios::beg);
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