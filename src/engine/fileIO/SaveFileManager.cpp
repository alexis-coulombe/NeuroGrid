#include "SaveFileManager.h"
#include "../../Config.h"
#include "../third_party/json.hpp"
#include "../Utils.h"
#include <filesystem>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

std::string getSaveFilePath();

bool SaveFileManager::saveGame() {
	std::string filename = getSaveFilePath() + "savegame.sav";
	printf("Save file path: %s\n", filename.c_str());
	std::fstream file(filename, std::ios::in | std::ios::out | std::ios::binary);

	if (!file) {
		std::cout << "Save file does not exist, creating a new one." << std::endl;
		std::filesystem::path savePath = getSaveFilePath();
		std::filesystem::create_directories(savePath);
		std::cout << "Save file does not exist, creating a new one." << std::endl;
		file.open(filename, std::ios::out | std::ios::binary);
		file.write(SAVE_FILE_VERSION, sizeof(SAVE_FILE_VERSION));
		file.close();
		// Re-open the file for reading and writing
		file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
	}

	uint8_t version = 0x00;
	file.read(reinterpret_cast<char *>(&version), sizeof(version));

	std::cout << "Save file version: " << (uint8_t)version << std::endl;

	file.seekg(sizeof(version), std::ios::beg);
	std::vector<char> jsonData((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	std::string jsonString(jsonData.begin(), jsonData.end());

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