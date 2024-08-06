#include "MissionState.h"

MissionState *MissionState::getInstance() {
	if (instance == nullptr) {
		instance = new MissionState();
	}
	return instance;
}