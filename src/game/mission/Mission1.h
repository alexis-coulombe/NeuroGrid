#ifndef ASM_SRC_GAME_MISSION_MISSION1_H_
#define ASM_SRC_GAME_MISSION_MISSION1_H_

/*
 * Mission1:
 * Simply copy all inputs in its respective output.
 */

#include "../../Config.h"
#include "Mission.h"

class Mission1: public Mission {
 public:
	static const uint8_t ID = 0x01;
	static const inline char *NAME = "Initial Calibration";
	static inline std::vector<char*> description = {
			(char*) "Reading Entry - 0xA3B4C2F1",
			(char*) "",
			(char*) "This foundational task will set everything that follows.",
			(char*) "The processors will learn to cooperate, to adapt.",
			(char*) "This initial calibration is just the beginning,",
			(char*) "it will be the proof that our vision is attainable.",
			(char*) "",
			(char*) "Every algorithm must be meticulously inscribed.",
			(char*) "Each line is a prayer to the purity of the machine.",
			(char*) "This is not mere preparation—it is a consecration.",
			(char*) "Success is our only creed; failure is heresy.",
	};
	static const inline char *instruction = "Copy all inputs in their respective outputs.";
	static const inline std::vector<uint8_t> Ainputs = {
			112,84,74,90,25,127,183,118,253,10,
			113,240,209,53,121,138,123,139,92,60,
			192,249,153,74,95,190,72,59,230,116,
			109,213,17,78,74,93,252,195,170,147
	};
	static const inline std::vector<uint8_t> Binputs = {
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0
	};
	static const inline std::vector<uint8_t> Cinputs = {
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0
	};

	static inline std::vector<uint8_t> Doutputs = {
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0
	};

	static inline std::vector<uint8_t> Eoutputs = {
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0
	};

	static inline std::vector<uint8_t> Foutputs = {
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0
	};

	Mission1();

	void setParsing(bool parsing) override;
	void setNanoParentContainer(NANOS nano, Container *container) override;
	void render(NANOS nano) override;

	std::vector<uint8_t> getAInputs() override;
	std::vector<uint8_t> getBInputs() override;
	std::vector<uint8_t> getCInputs() override;

	std::vector<uint8_t> getDOutputs() override;
	std::vector<uint8_t> getEOutputs() override;
	std::vector<uint8_t> getFOutputs() override;

	void setDOutput(uint8_t index, uint8_t value) override;
	void setEOutput(uint8_t index, uint8_t value) override;
	void setFOutput(uint8_t index, uint8_t value) override;
};

#endif //ASM_SRC_GAME_MISSION_MISSION1_H_
