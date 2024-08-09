#ifndef ASM_SRC_GAME_MISSIONMANAGER_H_
#define ASM_SRC_GAME_MISSIONMANAGER_H_

class MissionManager
{
protected:
	static inline MissionManager *instance = nullptr;

	MissionManager() = default;
	~MissionManager() = default;

public:
	enum MISSION_TYPE {
		INPUT_OUTPUT = 0
	};

	MissionManager(MissionManager &other) = delete;

	void operator=(const MissionManager &) = delete;
	static MissionManager *getInstance();
};

#endif // ASM_SRC_GAME_MISSIONMANAGER_H_
