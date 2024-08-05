#ifndef ASM_SRC_GAME_MISSION_MISSION1_H_
#define ASM_SRC_GAME_MISSION_MISSION1_H_

/*
 * Mission1:
 * Simply copy all inputs in its respective output.
 */

#include <cstdint>
#include <vector>

class Mission1 {
 public:
	const char *name = "Initial Calibration";
	const std::vector<char*> description = std::vector<char *>{
			(char *)"Reading Entry - 0xA3B4C2F1",
			(char *)"",
			(char *)"This foundational task will set everything that follows.",
			(char *)"The processors will learn to cooperate, to adapt.",
			(char *)"This initial calibration is just the beginning,",
			(char *)"it will be the proof that our vision is attainable.",
			(char *)"",
			(char *)"Every algorithm must be meticulously inscribed.",
			(char *)"Each line is a prayer to the purity of the machine.",
			(char *)"This is not mere preparation—it is a consecration.",
			(char *)"Success is our only creed; failure is heresy.",
	};
	const char *instruction = "Copy all inputs in their respective outputs.";
	const uint8_t inputs[40] = {
			112,84,74,90,25,127,183,118,253,10,
			113,240,209,53,121,138,123,139,92,60,
			192,249,153,74,95,190,72,59,230,116,
			109,213,17,78,74,93,252,195,170,147
	};
	const uint8_t outputs[40] = {0};
};

#endif //ASM_SRC_GAME_MISSION_MISSION1_H_
