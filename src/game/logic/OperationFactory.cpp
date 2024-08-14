#include "OperationFactory.h"
#include "operators/MovOperation.h"
#include "operators/NopOperation.h"

std::unique_ptr<Operation> OperationFactory::createOperation(OPERATION_TYPE operation) {
	switch (operation) {
		case OPERATION_TYPE::NOP: {
			std::make_unique<NopOperation>();
			break;
		}
		case OPERATION_TYPE::MOV: {
			std::make_unique<MovOperation>();
			break;
		}
		default: {
			return nullptr;
		}
	}

	return nullptr;
}