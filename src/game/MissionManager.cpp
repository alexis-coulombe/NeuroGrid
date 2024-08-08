#include "MissionManager.h"

MissionManager *MissionManager::getInstance() {
	if (instance == nullptr) {
		instance = new MissionManager();
	}
	return instance;
}