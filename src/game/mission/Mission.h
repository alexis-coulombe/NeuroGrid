#ifndef ASM_SRC_GAME_MISSION_MISSION_H_
#define ASM_SRC_GAME_MISSION_MISSION_H_

#include <cstdint>
#include <vector>
#include "../logic/Nano.h"
#include "../logic/NanoTextarea.h"
#include "../logic/NanoParser.h"

class Mission {
 protected:
	bool parsing = false;

	Nano nano1 = Nano(new NanoTextarea(nullptr, Vector2f(0, 0), 20, 20, Asset::loadFont((char *)"assets/ModernDOS.ttf", 10), Color::WHITE));
	Nano nano2 = Nano(new NanoTextarea(nullptr, Vector2f(0, 0), 20, 20, Asset::loadFont((char *)"assets/ModernDOS.ttf", 10), Color::WHITE));;
	Nano nano3 = Nano(new NanoTextarea(nullptr, Vector2f(0, 0), 20, 20, Asset::loadFont((char *)"assets/ModernDOS.ttf", 10), Color::WHITE));;
 public:
	enum NANOS {
		NANO1 = 0,
		NANO2,
		NANO3
	};

	NanoParser nanoParser = NanoParser(&nano1, &nano2, &nano3);

	virtual void setParsing(bool parsing) = 0;
	bool getParsing() { return parsing; };
	virtual void setNanoParentContainer(NANOS nano, Container *container) = 0;
	virtual void render(NANOS nano) = 0;

	virtual std::vector<uint8_t> getAInputs() = 0;
	virtual std::vector<uint8_t> getBInputs() = 0;
	virtual std::vector<uint8_t> getCInputs() = 0;

	virtual std::vector<uint8_t> getDOutputs() = 0;
	virtual std::vector<uint8_t> getEOutputs() = 0;
	virtual std::vector<uint8_t> getFOutputs() = 0;

	virtual void setDOutput(uint8_t index, uint8_t value) = 0;
	virtual void setEOutput(uint8_t index, uint8_t value) = 0;
	virtual void setFOutput(uint8_t index, uint8_t value) = 0;
};

#endif //ASM_SRC_GAME_MISSION_MISSION_H_
