#ifndef ASM_SRC_GAME_MISSION_MISSION2_H_
#define ASM_SRC_GAME_MISSION_MISSION2_H_

#include <vector>
#include <string>
#include "../Mission.h"
/*
 * Mission2:
 * Transfer all given inputs to its respective outputs.
 * - Cap the output values to 200.
 * - Values less than 5 must be 15.
 */

class Mission2 : public Mission {
 public:
	static const uint8_t ID = 1;
	static const inline char *NAME = "Cadence of necrosis";
	virtual std::vector<std::string> getIntro() {
		return {
				"> Reading Entry - 0x41DEAF78",
				"",
				"I can feel it, the signals racing through my own nervous system.",
				"Synapses firing at the neuromuscular junction.",
				"",
				"A signal too strong and the muscle contracts violently,",
				"tearing itself apart.",
				"I've seen it before, flesh twisted into rigid, unnatural shapes.",
				"The actin-myosin cross-bridges don’t break, they *snap*, leaving necrosis.",
				"",
				"Under-stimulation is no kinder.",
				"A signal too weak, and the muscles starve, falling silent as they rot.",
				"Necrotic, fibers—eaten away by their failure, consumed by entropy.",
				"Death by quiet suffocation of the cells.",
				"",
				"Overload burns through them like a wildfire;",
				"undervoltage leaves them as hollow as dying nerves."
		};
	}

	virtual std::vector<std::string> getDescription() {
		return {
				"Copy all inputs in their respective outputs.",
				"",
				"- Clamp the output values to 5-200.",
				"- Values equals to 0 must be copied as 1.",
		};
	}

	static inline std::vector<uint8_t> *inputsA = new std::vector<uint8_t>{
			69, 112, 65, 167, 232, 34, 6, 245, 97, 162,
			49, 206, 88, 134, 101, 78, 22, 111, 224, 206,
			179, 234, 51, 148, 246, 53, 95, 147, 224, 97,
			28, 102, 236, 54, 1, 76, 201, 198, 243, 82
	};
	static inline std::vector<uint8_t> *inputsB = new std::vector<uint8_t>{
			201, 0, 34, 121, 75, 222, 226, 18, 43, 230,
			198, 178, 167, 138, 239, 141, 132, 60, 156, 242,
			155, 92, 198, 145, 49, 244, 88, 36, 53, 0,
			91, 134, 111, 87, 0, 88, 161, 220, 251, 156
	};
	static inline std::vector<uint8_t> *inputsC = new std::vector<uint8_t>{
			124, 114, 93, 248, 126, 234, 170, 88, 156, 230,
			33, 200, 234, 76, 123, 119, 212, 65, 42, 201,
			85, 45, 147, 57, 157, 135, 105, 247, 177, 11,
			3, 171, 124, 164, 178, 106, 191, 169, 252, 116
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
				69, 112, 65, 167, 200, 34, 6, 200, 97, 162,
				49, 200, 88, 134, 101, 78, 22, 111, 200, 200,
				179, 200, 51, 148, 200, 53, 95, 147, 200, 97,
				28, 102, 236, 54, 15, 76, 200, 198, 200, 82
		};
		std::vector<uint8_t> expectedOutputE = {
				200, 15, 34, 121, 75, 200, 200, 18, 43, 200,
				198, 178, 167, 138, 200, 141, 132, 60, 156, 200,
				155, 92, 198, 145, 49, 200, 88, 36, 53, 15,
				91, 134, 111, 87, 15, 88, 161, 200, 200, 156
		};
		std::vector<uint8_t> expectedOutputF = {
				124, 114, 93, 200, 126, 200, 170, 88, 156, 200,
				33, 200, 200, 76, 123, 119, 200, 65, 42, 200,
				85, 45, 147, 57, 157, 135, 105, 200, 177, 11,
				15, 171, 124, 164, 178, 106, 191, 169, 200, 116
		};

		return *outputsD == expectedOutputD && *outputsE == expectedOutputE && *outputsF == expectedOutputF;
	}
};

#endif //ASM_SRC_GAME_MISSION_MISSION2_H_
