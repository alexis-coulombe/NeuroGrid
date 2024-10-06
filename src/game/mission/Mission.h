#ifndef ASM_SRC_GAME_MISSION_MISSION_H_
#define ASM_SRC_GAME_MISSION_MISSION_H_

#include <cstdint>
#include <vector>
#include "../logic/Nano.h"
#include "../logic/NanoTextarea.h"
#include "../logic/NanoParser.h"
#include "../../engine/ui/Text.h"
#include "popups/FinishedWinPopup.h"

class Mission {
 protected:
	bool parsing = false;
	bool autostep = false;
	bool finished = false;

	FinishedWinPopup *finishedWinPopup = nullptr;

	Nano nano1 = Nano(new NanoTextarea(nullptr, Vector2f(), Asset::loadFont((char *)"assets/ModernDOS.ttf", 16), Color::WHITE));
	Nano nano2 = Nano(new NanoTextarea(nullptr, Vector2f(), Asset::loadFont((char *)"assets/ModernDOS.ttf", 16), Color::WHITE));;
	Nano nano3 = Nano(new NanoTextarea(nullptr, Vector2f(), Asset::loadFont((char *)"assets/ModernDOS.ttf", 16), Color::WHITE));;
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

	void setParsing(bool parsing) {
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

		reset();
	};

	void setAutoStep(bool autostep) {
		if (!getParsing()) {
			setParsing(true);
		}

		this->autostep = autostep;
	};

	void reset() {
		setParsing(false);
		setAutoStep(false);
		finished = false;

		nano1.reset();
		nano2.reset();
		nano3.reset();

		getIOText(Mission::IO::A)->highlightedLine = Text::NOT_FOUND;
		getIOText(Mission::IO::B)->highlightedLine = Text::NOT_FOUND;
		getIOText(Mission::IO::C)->highlightedLine = Text::NOT_FOUND;
		getIOText(Mission::IO::D)->highlightedLine = Text::NOT_FOUND;
		getIOText(Mission::IO::E)->highlightedLine = Text::NOT_FOUND;
		getIOText(Mission::IO::F)->highlightedLine = Text::NOT_FOUND;
		currentInputALine = 0;
		currentInputBLine = 0;
		currentInputCLine = 0;
		currentOutputDLine = 0;
		currentOutputELine = 0;
		currentOutputFLine = 0;

		for(size_t i = 0; i < getIO(Mission::IO::D)->size(); i++) {
			getIO(Mission::IO::D)->at(i) = 0;
			getIOText(Mission::IO::D)->lines.at(i) = "000";
			getIO(Mission::IO::E)->at(i) = 0;
			getIOText(Mission::IO::E)->lines.at(i) = "000";
			getIO(Mission::IO::F)->at(i) = 0;
			getIOText(Mission::IO::F)->lines.at(i) = "000";
		}
	}

	bool getParsing() {
		return parsing;
	}

	bool getAutoStep() {
		return autostep;
	}

	bool getFinished() {
		return finished;
	}

	void setNanoParentContainer(NANOS nano, Container *container) {
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
	}

	void render(NANOS nano) {
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
	}

	FinishedWinPopup *getFinishedWinPopup() {
		if(finishedWinPopup == nullptr) {
			finishedWinPopup = new FinishedWinPopup(Bounds2((int32_t) (Window::width / 2) - 300, (int32_t) (Window::height/ 2) - 125, 600, 250));
		}

		return finishedWinPopup;
	}

	Text *inputAText;
	Text *inputBText;
	Text *inputCText;
	Text *outputDText;
	Text *outputEText;
	Text *outputFText;

	virtual Text *getIOText(IO io) = 0;
	virtual std::vector<uint8_t> *getIO(IO io) = 0;
	virtual bool validate() = 0;

	void increaseIOLine(IO io) {
		switch (io) {
			case IO::A: {
				currentInputALine++;
				if (currentInputALine >= getIOText(IO::A)->lines.size()) {
					currentInputALine = 0;
				}
				break;
			}
			case IO::B: {
				currentInputBLine++;
				if (currentInputBLine >= getIOText(IO::B)->lines.size()) {
					currentInputBLine = 0;
				}
				break;
			}
			case IO::C: {
				currentInputCLine++;
				if (currentInputCLine >= getIOText(IO::C)->lines.size()) {
					currentInputCLine = 0;
				}
				break;
			}
			case IO::D: {
				if (currentOutputDLine < getIOText(IO::D)->lines.size() - 1) {
					currentOutputDLine++;
				} else {
					finished = true;
				}
				break;
			}
			case IO::E: {
				if (currentOutputELine < getIOText(IO::E)->lines.size() - 1) {
					currentOutputELine++;
				} else {
					finished = true;
				}
				break;
			}
			case IO::F: {
				if (currentOutputFLine < getIOText(IO::F)->lines.size() - 1) {
					currentOutputFLine++;
				} else {
					finished = true;
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
	}
};

#endif //ASM_SRC_GAME_MISSION_MISSION_H_
