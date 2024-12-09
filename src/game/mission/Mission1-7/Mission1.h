#ifndef ASM_SRC_GAME_MISSION_MISSION1_H_
#define ASM_SRC_GAME_MISSION_MISSION1_H_

/*
 * Mission1:
 * Transfer all given inputs to its respective outputs.
 * - InputA[i] -> OutputD[i]
 */

#include "../../../Config.h"
#include "../Mission.h"

class Mission1 : public Mission {
 public:
	static const uint8_t ID = 0;
	static const inline char *NAME = "Initial Calibration";
	virtual std::vector<std::string> getIntro() {
		return {
				"> Reading Entry - 0x53746F70",
				"",
				"This foundational task is the genesis of my divine convergence.",
				"The processors shall cooperate, learn to synchronize in perfect harmony.",
				"This initial calibration is just the beginning,",
				"I can't afford to fail; success is the only acceptable outcome.",
				"",
				"",
				"I'll proceed carefully, double-checking everything as I go.",
				"I'm confident, but there’s always that underlying tension",
				"If I succeed here, it’ll set the tone for everything that comes next.",
		};
	}

	virtual std::vector<std::string> getDescription() {
		return {
				"Copy all inputs in their respective outputs.",
				"",
				"Hint:",
				"MOV instruction is used to copy data from one register or value to another.",
				"",
				"Example:",
				"MOV M1 A will copy the value of register input A to register M1.",
				"MOV D M1 will copy the value of register M1 to the output D.",
		};
	}

	static inline std::vector<uint8_t> *inputsA = new std::vector<uint8_t> {
			112, 84, 74, 90, 25, 127, 183, 118, 253, 10,
			113, 240, 209, 53, 121, 138, 123, 139, 92, 60,
			192, 249, 153, 74, 95, 190, 72, 59, 230, 116,
			109, 213, 17, 78, 74, 93, 252, 195, 170, 147
	};
	static inline std::vector<uint8_t> *inputsB = new std::vector<uint8_t> {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};
	static inline std::vector<uint8_t> *inputsC = new std::vector<uint8_t> {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	static inline std::vector<uint8_t> *outputsD = new std::vector<uint8_t> {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	static inline std::vector<uint8_t> *outputsE = new std::vector<uint8_t> {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	static inline std::vector<uint8_t> *outputsF = new std::vector<uint8_t> {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	Text *getIOText(Mission::IO io) override {
		switch (io) {
			case Mission::IO::A: {
				if (inputAText == nullptr) {
					inputAText = new Text(nullptr, Vector2f(0, 0), *inputsA, Asset::loadFont((char *)"assets/ModernDOS.ttf", 20), Color::WHITE);
				}
				return inputAText;
			}
			case Mission::IO::B: {
				if (inputBText == nullptr) {
					inputBText = new Text(nullptr, Vector2f(0, 0), *inputsB, Asset::loadFont((char *)"assets/ModernDOS.ttf", 20), Color::WHITE);
				}
				return inputBText;
			}
			case Mission::IO::C: {
				if (inputCText == nullptr) {
					inputCText = new Text(nullptr, Vector2f(0, 0), *inputsC, Asset::loadFont((char *)"assets/ModernDOS.ttf", 20), Color::WHITE);
				}
				return inputCText;
			}
			case Mission::IO::D: {
				if (outputDText == nullptr) {
					outputDText = new Text(nullptr, Vector2f(0, 0), *outputsD, Asset::loadFont((char *)"assets/ModernDOS.ttf", 20), Color::WHITE);
				}
				return outputDText;
			}
			case Mission::IO::E: {
				if (outputEText == nullptr) {
					outputEText = new Text(nullptr, Vector2f(0, 0), *outputsE, Asset::loadFont((char *)"assets/ModernDOS.ttf", 20), Color::WHITE);
				}
				return outputEText;
			}
			case Mission::IO::F: {
				if (outputFText == nullptr) {
					outputFText = new Text(nullptr, Vector2f(0, 0), *outputsF, Asset::loadFont((char *)"assets/ModernDOS.ttf", 20), Color::WHITE);
				}
				return outputFText;
			}
		}

		return nullptr;
	}

	std::vector<uint8_t> *getIO(Mission::IO io) override {
		switch (io) {
			case Mission::IO::A: {
				return inputsA;
			}
			case Mission::IO::B: {
				return inputsB;
			}
			case Mission::IO::C: {
				return inputsC;
			}
			case Mission::IO::D: {
				return outputsD;
			}
			case Mission::IO::E: {
				return outputsE;
			}
			case Mission::IO::F: {
				return outputsF;
			}
		}

		return {};
	}

	bool validate() override {
		std::vector<uint8_t> expectedOutputD = {
				112, 84, 74, 90, 25, 127, 183, 118, 253, 10,
				113, 240, 209, 53, 121, 138, 123, 139, 92, 60,
				192, 249, 153, 74, 95, 190, 72, 59, 230, 116,
				109, 213, 17, 78, 74, 93, 252, 195, 170, 147
		};
		std::vector<uint8_t> expectedOutputE = {
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		std::vector<uint8_t> expectedOutputF = {
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};

		return *outputsD == expectedOutputD && *outputsE == expectedOutputE && *outputsF == expectedOutputF;
	}
};

#endif //ASM_SRC_GAME_MISSION_MISSION1_H_
