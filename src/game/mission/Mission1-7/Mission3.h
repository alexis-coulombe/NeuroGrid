#ifndef ASM_SRC_GAME_MISSION_MISSION1_7_MISSION3_H_
#define ASM_SRC_GAME_MISSION_MISSION1_7_MISSION3_H_

#include "../Mission.h"
/*
 * Mission5:
 * A sequence of two numbers are given.
 * The third number is the result of the operation.
 * If the operation is invalid, the rest of the outputs must be 0.
 * else the result must be the result of the operation.
 *
 * Inputs[A,B,C] = [1, 2, 3] -> OutputsD = 3
 * Inputs[A,B,C] = [2, 2, 12] -> OutputsD = 0
 * Inputs[A,B,C] = [2, 0, 2] -> OutputsD = 0
 */

class Mission3 : public Mission {
 public:
	static const uint8_t ID = 2;
	static const inline char *NAME = "Veil of decay";
	virtual std::vector<std::string> getIntro() {
		return {
				"> Reading Entry - 0xB5D7F3A9",
				"",
				"The system’s lifeblood lies in its data; pure, untouchable",
				"If I can’t stabilize it soon, the entire structure will crumble.",
				"Taking me with it.",
				"",
				"What should’ve been clean has turned into a full-blown crisis.",
				"The data arteries are clogged with corruption.",
				"I’m trying to stave off the inevitable, but it's eating itself.",
				"Every second that passes, the system is closer to colla¶ ¦«",
				"",
				"[PANIC] At 0x1000 - no response from core systems",
				"",
				"",
				"",
				"",
		};
	}

	virtual std::vector<std::string> getDescription() {
		return {
				"A sequence of two numbers are given. The third number is the result of the operation.",
				"The D output must be the actual result of the operation."
				"The E output contains a boolean, signaling if the operation was valid.",
				"",
				"Inputs[A,B,C] -> Output[D,E,F] => [1,2,3] -> [3,1,0]",
				"Inputs[A,B,C] -> Output[D,E,F] => [2,2,12] -> [4,0,0]",
				"Inputs[A,B,C] -> Output[D,E,F] => [2,0,2] -> [2,1,0]",
		};
	}

	static inline std::vector<uint8_t> *inputsA = new std::vector<uint8_t>{
			65, 8, 25, 20, 100, 63, 21, 108, 103, 42,
			97, 97, 91, 8, 105, 58, 6, 88, 82, 108,
			67, 78, 50, 50, 107, 65, 95, 45, 45, 84,
			110, 13, 65, 25, 78, 38, 4, 89, 11, 76
	};
	static inline std::vector<uint8_t> *inputsB = new std::vector<uint8_t>{
			64, 118, 16, 32, 22, 10, 53, 100, 33, 21,
			50, 49, 64, 111, 20, 115, 85, 113, 92, 30,
			20, 66, 64, 3, 88, 122, 104, 0, 85, 94,
			124, 33, 57, 81, 3, 101, 25, 4, 111, 69
	};
	static inline std::vector<uint8_t> *inputsC = new std::vector<uint8_t>{
			129, 126, 41, 123, 116, 9, 124, 208, 46, 98,
			91, 108, 155, 119, 125, 14, 24, 109, 33, 101,
			38, 87, 84, 82, 38, 63, 80, 130, 87, 7,
			34, 112, 81, 62, 102, 81, 0, 93, 16, 145
	};

	static inline std::vector<uint8_t> *outputsD = new std::vector<uint8_t>{
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	static inline std::vector<uint8_t> *outputsE = new std::vector<uint8_t>{
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	static inline std::vector<uint8_t> *outputsF = new std::vector<uint8_t>{
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
				129, 126, 41, 52, 122, 73, 74, 208, 136, 63,
				147, 146, 155, 119, 125, 173, 91, 201, 174, 138,
				87, 144, 114, 53, 195, 187, 199, 45, 130, 178,
				234, 46, 122, 106, 81, 139, 29, 93, 122, 145
		};
		std::vector<uint8_t> expectedOutputE = {
				1, 1, 1, 0, 0, 0, 0, 1, 0, 0,
				0, 0, 1, 1, 1, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 1, 0, 1
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

#endif //ASM_SRC_GAME_MISSION_MISSION1_7_MISSION3_H_
