#ifndef ASM_SRC_GAME_MISSIONMANAGER_H_
#define ASM_SRC_GAME_MISSIONMANAGER_H_

#include <cstdint>
#include "mission/Mission.h"

class MissionManager
{
protected:
	static inline MissionManager *instance = nullptr;

	MissionManager() = default;
	~MissionManager() = default;

 public:
	Mission *currentMission = nullptr;
	enum MISSION_TYPE {
		NONE = 0,
		INPUT_OUTPUT
	};

	MissionManager(MissionManager &other) = delete;

	void updateCurrentMission(uint8_t missionID);

	void operator=(const MissionManager &) = delete;
	static MissionManager *getInstance();
};

#endif // ASM_SRC_GAME_MISSIONMANAGER_H_
