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
	static const uint8_t ID = 0x01;
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

	static const inline char *instruction = "Copy all inputs in their respective outputs.";
	static const inline std::vector<uint8_t> inputsA = {
			112, 84, 74, 90, 25, 127, 183, 118, 253, 10,
			113, 240, 209, 53, 121, 138, 123, 139, 92, 60,
			192, 249, 153, 74, 95, 190, 72, 59, 230, 116,
			109, 213, 17, 78, 74, 93, 252, 195, 170, 147
	};
	static const inline std::vector<uint8_t> inputsB = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};
	static const inline std::vector<uint8_t> inputsC = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	static inline std::vector<uint8_t> outputsD = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	static inline std::vector<uint8_t> outputsE = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	static inline std::vector<uint8_t> outputsF = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	Text *inputAText;
	Text *inputBText;
	Text *inputCText;
	Text *outputDText;
	Text *outputEText;
	Text *outputFText;

	Text *getInputAText() override {
		if (inputAText == nullptr) {
			inputAText = new Text(nullptr, Vector2f(0, 0), inputsA, Asset::loadFont((char *)"assets/ModernDOS.ttf", 20), Color::WHITE);
		}
		return inputAText;
	}

	Text *getInputBText() override {
		if (inputBText == nullptr) {
			inputBText = new Text(nullptr, Vector2f(0, 0), inputsB, Asset::loadFont((char *)"assets/ModernDOS.ttf", 20), Color::WHITE);
		}
		return inputBText;
	}

	Text *getInputCText() override {
		if (inputCText == nullptr) {
			inputCText = new Text(nullptr, Vector2f(0, 0), inputsC, Asset::loadFont((char *)"assets/ModernDOS.ttf", 20), Color::WHITE);
		}
		return inputCText;
	}

	Text *getOutputDText() override {
		if (outputDText == nullptr) {
			outputDText = new Text(nullptr, Vector2f(0, 0), outputsD, Asset::loadFont((char *)"assets/ModernDOS.ttf", 20), Color::WHITE);
		}
		return outputDText;
	}

	Text *getOutputEText() override {
		if(outputEText == nullptr) {
			outputEText = new Text(nullptr, Vector2f(0, 0), outputsE, Asset::loadFont((char *)"assets/ModernDOS.ttf", 20), Color::WHITE);
		}
		return outputEText;
	}

	Text *getOutputFText() override {
		if(outputFText == nullptr) {
			outputFText = new Text(nullptr, Vector2f(0, 0), outputsF, Asset::loadFont((char *)"assets/ModernDOS.ttf", 20), Color::WHITE);
		}
		return outputFText;
	}

	void setParsing(bool parsing) override {
		if (this->parsing == parsing) {
			return;
		}

		this->parsing = parsing;

		if (parsing) {
			nano1.code->readonly = true;
			nano2.code->readonly = true;
			nano3.code->readonly = true;
			return;
		}

		nano1.reset();
		nano2.reset();
		nano3.reset();
	};

	void stepParsing() override {
		if (!parsing) {
			return;
		}

		nanoParser.step();
	};

	void setNanoParentContainer(NANOS nano, Container *container) override {
		switch (nano) {
			case Mission::NANO1: {
				nano1.setParentContainer(container);
				nano1.code->bounds->position.x = container->bounds.position.x + (container->bounds.size.x - nano1.code->bounds->size.x) / 2;
				nano1.code->bounds->position.y = container->bounds.position.y + (container->bounds.size.y - nano1.code->bounds->size.y) / 2;
				break;
			}
			case Mission::NANO2: {
				nano2.setParentContainer(container);
				nano2.code->bounds->position.x = container->bounds.position.x + (container->bounds.size.x - nano2.code->bounds->size.x) / 2;
				nano2.code->bounds->position.y = container->bounds.position.y + (container->bounds.size.y - nano2.code->bounds->size.y) / 2;
				break;
			}
			case Mission::NANO3: {
				nano3.setParentContainer(container);
				nano3.code->bounds->position.x = container->bounds.position.x + (container->bounds.size.x - nano3.code->bounds->size.x) / 2;
				nano3.code->bounds->position.y = container->bounds.position.y + (container->bounds.size.y - nano3.code->bounds->size.y) / 2;
				break;
			}
			default: {
				break;
			}
		}
	};

	void render(NANOS nano) override {
		switch (nano) {
			case Mission::NANO1: {
				nano1.render();
				break;
			}
			case Mission::NANO2: {
				nano2.render();
				break;
			}
			case Mission::NANO3: {
				nano3.render();
				break;
			}
			default: {
				break;
			}
		}
	};

	std::vector<uint8_t> getAInputs() override {
		return inputsA;
	};

	std::vector<uint8_t> getBInputs() override {
		return inputsB;
	};

	std::vector<uint8_t> getCInputs() override {
		return inputsC;
	};

	std::vector<uint8_t> getDOutputs() override {
		return outputsD;
	};

	std::vector<uint8_t> getEOutputs() override {
		return outputsE;
	};

	std::vector<uint8_t> getFOutputs() override {
		return outputsF;
	};
};

#endif //ASM_SRC_GAME_MISSION_MISSION1_H_
