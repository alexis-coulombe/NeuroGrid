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

	std::vector<uint8_t> getMissionAInputs();
	std::vector<uint8_t> getMissionBInputs();
	std::vector<uint8_t> getMissionCInputs();
	std::vector<uint8_t> getMissionDOutputs();
	std::vector<uint8_t> getMissionEOutputs();
	std::vector<uint8_t> getMissionFOutputs();

	void operator=(const MissionManager &) = delete;
	static MissionManager *getInstance();
};

#endif // ASM_SRC_GAME_MISSIONMANAGER_H_
