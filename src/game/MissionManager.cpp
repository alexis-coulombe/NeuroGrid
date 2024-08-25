#include "MissionManager.h"
#include "mission/Mission1-7/Mission1.h"

MissionManager *MissionManager::getInstance() {
	if (instance == nullptr) {
		instance = new MissionManager();
	}
	return instance;
}

void MissionManager::updateCurrentMission(uint8_t missionID) {
	switch (missionID) {
		case Mission1::ID:
			currentMission = new Mission1();
			break;
		default:
			currentMission = nullptr;
			break;
	}
}

std::vector<uint8_t> MissionManager::getMissionAInputs() {
	return currentMission->getAInputs();
}

std::vector<uint8_t> MissionManager::getMissionBInputs() {
	return currentMission->getBInputs();
}

std::vector<uint8_t> MissionManager::getMissionCInputs() {
	return currentMission->getCInputs();
}

std::vector<uint8_t> MissionManager::getMissionDOutputs() {
	return currentMission->getDOutputs();
}

std::vector<uint8_t> MissionManager::getMissionEOutputs() {
	return currentMission->getEOutputs();
}

std::vector<uint8_t> MissionManager::getMissionFOutputs() {
	return currentMission->getFOutputs();
}