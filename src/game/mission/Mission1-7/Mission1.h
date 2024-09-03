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
	static inline std::vector<std::string> description = {
			"> Reading Entry - 0xA3B4C2F1",
			"",
			"[LOG] Fetching entry...",
			"[LOG] Done.",
			"",
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
	static const inline char *instruction = "Copy all inputs in their respective outputs.";
	static const inline std::vector<uint8_t> Ainputs = {
			112, 84, 74, 90, 25, 127, 183, 118, 253, 10,
			113, 240, 209, 53, 121, 138, 123, 139, 92, 60,
			192, 249, 153, 74, 95, 190, 72, 59, 230, 116,
			109, 213, 17, 78, 74, 93, 252, 195, 170, 147
	};
	static const inline std::vector<uint8_t> Binputs = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};
	static const inline std::vector<uint8_t> Cinputs = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	static inline std::vector<uint8_t> Doutputs = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	static inline std::vector<uint8_t> Eoutputs = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	static inline std::vector<uint8_t> Foutputs = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	void setParsing(bool parsing) override {
		if(this->parsing == parsing) {
			return;
		}

		this->parsing = parsing;

		if (parsing) {
			nano1.code->readonly = true;
			nano2.code->readonly = true;
			nano3.code->readonly = true;

			nanoParser.currentCycle = 0;

			return;
		}

		nano1.code->readonly = false;
		nano2.code->readonly = false;
		nano3.code->readonly = false;

		nano1.code->highlightedLine = 0xFF;
		nano2.code->highlightedLine = 0xFF;
		nano3.code->highlightedLine = 0xFF;

		nanoParser.currentCycle = 0;
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
				// Center the nano code textarea in container
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
		return Ainputs;
	};

	std::vector<uint8_t> getBInputs() override {
		return Binputs;
	};

	std::vector<uint8_t> getCInputs() override {
		return Cinputs;
	};

	std::vector<uint8_t> getDOutputs() override {
		return Doutputs;
	};

	std::vector<uint8_t> getEOutputs() override {
		return Eoutputs;
	};

	std::vector<uint8_t> getFOutputs() override {
		return Foutputs;
	};

	void setDOutput(uint8_t index, uint8_t value) override {
		Doutputs.at(index) = value;
	};

	void setEOutput(uint8_t index, uint8_t value) override {
		Eoutputs.at(index) = value;
	};

	void setFOutput(uint8_t index, uint8_t value) override {
		Foutputs.at(index) = value;
	};
};

#endif //ASM_SRC_GAME_MISSION_MISSION1_H_
