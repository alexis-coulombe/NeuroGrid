#include "Mission1.h"

Mission1::Mission1() : Mission() {
}

void Mission1::setParsing(bool parsing) {
	parsingMode = parsing;

	if(parsing) {
		nano1.code->readonly = true;
		nano2.code->readonly = true;
		nano3.code->readonly = true;

		nanoParser.currentCycle = 0;

		return;
	}

	nano1.code->readonly = false;
	nano2.code->readonly = false;
	nano3.code->readonly = false;

	nanoParser.currentCycle = 0;
}

void Mission1::setNanoParentContainer(NANOS nano, Container *container) {
	switch (nano) {
		case Mission::NANO1: {
			nano1.setParentContainer(container);
			break;
		}
		case Mission::NANO2: {
			nano2.setParentContainer(container);
			break;
		}
		case Mission::NANO3: {
			nano3.setParentContainer(container);
			break;
		}
		default: {
			break;
		}
	}
}

void Mission1::render(NANOS nano) {
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

std::vector<uint8_t> Mission1::getAInputs() {
	return Ainputs;
}

std::vector<uint8_t> Mission1::getBInputs() {
	return Binputs;
}

std::vector<uint8_t> Mission1::getCInputs() {
	return Cinputs;
}

std::vector<uint8_t> Mission1::getDOutputs() {
	return Doutputs;
}

std::vector<uint8_t> Mission1::getEOutputs() {
	return Eoutputs;
}

std::vector<uint8_t> Mission1::getFOutputs() {
	return Foutputs;
}

void Mission1::setDOutput(uint8_t index, uint8_t value) {
	Doutputs.at(index) = value;
}

void Mission1::setEOutput(uint8_t index, uint8_t value) {
	Eoutputs.at(index) = value;
}

void Mission1::setFOutput(uint8_t index, uint8_t value) {
	Foutputs.at(index) = value;
}