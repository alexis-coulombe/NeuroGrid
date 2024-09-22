#ifndef ASM_SRC_GAME_MISSION_MISSION_H_
#define ASM_SRC_GAME_MISSION_MISSION_H_

#include <cstdint>
#include <vector>
#include "../logic/Nano.h"
#include "../logic/NanoTextarea.h"
#include "../logic/NanoParser.h"
#include "../../engine/ui/Text.h"

class Mission {
 protected:
	bool parsing = false;
	bool autostep = false;

	Nano nano1 = Nano(new NanoTextarea(nullptr, Vector2f(), 20, 20, Asset::loadFont((char *)"assets/ModernDOS.ttf", 16), Color::WHITE));
	Nano nano2 = Nano(new NanoTextarea(nullptr, Vector2f(), 20, 20, Asset::loadFont((char *)"assets/ModernDOS.ttf", 16), Color::WHITE));;
	Nano nano3 = Nano(new NanoTextarea(nullptr, Vector2f(), 20, 20, Asset::loadFont((char *)"assets/ModernDOS.ttf", 16), Color::WHITE));;
 public:
	enum NANOS {
		NANO1 = 0,
		NANO2,
		NANO3
	};

	enum IO {
		A,
		B,
		C,
		D,
		E,
		F
	};

	uint8_t currentInputALine = 0;
	uint8_t currentInputBLine = 0;
	uint8_t currentInputCLine = 0;
	uint8_t currentOutputDLine = 0;
	uint8_t currentOutputELine = 0;
	uint8_t currentOutputFLine = 0;

	NanoParser nanoParser = NanoParser(&nano1, &nano2, &nano3);

	virtual std::vector<std::string> getIntro() = 0;
	virtual std::vector<std::string> getDescription() = 0;

	virtual void setParsing(bool parsing) = 0;
	virtual void setAutoStep(bool autostep) = 0;
	virtual void stepParsing() = 0;
	bool getParsing() { return parsing; };
	bool getAutoStep() { return autostep; };
	virtual void setNanoParentContainer(NANOS nano, Container *container) = 0;
	virtual void render(NANOS nano) = 0;

	virtual Text *getInputAText() = 0;
	virtual Text *getInputBText() = 0;
	virtual Text *getInputCText() = 0;
	virtual Text *getOutputDText() = 0;
	virtual Text *getOutputEText() = 0;
	virtual Text *getOutputFText() = 0;

	virtual std::vector<uint8_t> getAInputs() = 0;
	virtual std::vector<uint8_t> getBInputs() = 0;
	virtual std::vector<uint8_t> getCInputs() = 0;
	virtual std::vector<uint8_t> getDOutputs() = 0;
	virtual std::vector<uint8_t> getEOutputs() = 0;
	virtual std::vector<uint8_t> getFOutputs() = 0;

	void increaseIOLine(IO io) {
		switch (io) {
			case IO::A: {
				currentInputALine++;
				if (currentInputALine >= getInputAText()->lines.size()) {
					currentInputALine = 0;
				}
				break;
			}
			case IO::B: {
				currentInputBLine++;
				if (currentInputBLine >= getInputBText()->lines.size()) {
					currentInputBLine = 0;
				}
				break;
			}
			case IO::C: {
				currentInputCLine++;
				if (currentInputCLine >= getInputCText()->lines.size()) {
					currentInputCLine = 0;
				}
				break;
			}
			case IO::D: {
				if (currentOutputDLine < getOutputDText()->lines.size()) {
					currentOutputDLine++;
				}
				break;
			}
			case IO::E: {
				if (currentOutputELine < getOutputEText()->lines.size()) {
					currentOutputELine++;
				}
				break;
			}
			case IO::F: {
				if (currentOutputFLine < getOutputFText()->lines.size()) {
					currentOutputFLine++;
				}
				break;
			}
		}
	}

	Nano *getNano(NANOS nano) {
		switch (nano) {
			case NANO1: {
				return &nano1;
			}
			case NANO2: {
				return &nano2;
			}
			case NANO3: {
				return &nano3;
			}
			default: {
				return nullptr;
			}
		}
	};
};

#endif //ASM_SRC_GAME_MISSION_MISSION_H_
