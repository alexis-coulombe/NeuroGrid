#ifndef ASM_SRC_GAME_MISSIONSTATE_H_
#define ASM_SRC_GAME_MISSIONSTATE_H_

class MissionState {
 protected:
	static inline MissionState *instance = nullptr;

	MissionState() = default;
	~MissionState() = default;

 public:
	MissionState(MissionState &other) = delete;

	void operator=(const MissionState &) = delete;
	static MissionState *getInstance();
};

#endif //ASM_SRC_GAME_MISSIONSTATE_H_
