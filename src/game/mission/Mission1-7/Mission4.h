#ifndef ASM_SRC_GAME_MISSION_MISSION3_H_
#define ASM_SRC_GAME_MISSION_MISSION3_H_

#include "../Mission.h"
/*
 * Mission3:
 * The three inputs are the values of a 3D vector (x, y, z).
 * The next three inputs must be added to the vector.
 * The result must be stored in the outputs in the same row.
 *
 * Inputs[A0][B0][C0] + Inputs[A1][B1][C1] -> Outputs[D0][E0][F0]
 */

class Mission3 : public Mission {
 public:
	static const uint8_t ID = 3;
	static const inline char *NAME = "Initial Calibration";
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
			55, 0, 42, 27, 66, 83, 42, 34, 11, 12,
			73, 9, 41, 34, 1, 4, 18, 68, 31, 9,
			55, 2, 9, 16, 81, 50, 31, 51, 44, 11,
			23, 46, 63, 55, 10, 36, 61, 6, 34, 67
	};
	static inline std::vector<uint8_t> *inputsB = new std::vector<uint8_t>{
			12, 8, 51, 13, 17, 33, 11, 19, 5, 46,
			46, 25, 16, 65, 79, 11, 75, 80, 54, 4,
			69, 26, 63, 20, 0, 29, 5, 33, 11, 66,
			82, 51, 59, 52, 34, 64, 80, 72, 17, 66
	};
	static inline std::vector<uint8_t> *inputsC = new std::vector<uint8_t>{
			29, 69, 11, 3, 83, 54, 62, 27, 20, 2,
			25, 42, 53, 17, 83, 42, 31, 44, 51, 36,
			36, 63, 72, 53, 6, 41, 73, 21, 74, 29,
			43, 9, 82, 60, 13, 72, 15, 49, 66, 31
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
				55, 69, 149, 76, 23, 82, 75, 5, 86, 40,
				57, 25, 131, 82, 55, 69, 118, 46, 67, 101,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		std::vector<uint8_t> expectedOutputE = {
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // TODO
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // TODO
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		std::vector<uint8_t> expectedOutputF = {
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // TODO
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // TODO
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};

		return *outputsD == expectedOutputD && *outputsE == expectedOutputE && *outputsF == expectedOutputF;
	}
};

#endif //ASM_SRC_GAME_MISSION_MISSION3_H_
