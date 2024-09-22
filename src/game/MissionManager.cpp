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