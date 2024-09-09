#include "OperationFactory.h"
#include "operators/MovOperation.h"
#include "operators/NopOperation.h"
#include "operators/AddOperation.h"
#include "operators/SubOperation.h"

std::unique_ptr<Operation> OperationFactory::createOperation(OPERATION_TYPE operation) {
	switch (operation) {
		case OPERATION_TYPE::NOP: {
			return std::make_unique<NopOperation>();
		}
		case OPERATION_TYPE::MOV: {
			return std::make_unique<MovOperation>();
		}
		case OPERATION_TYPE::ADD: {
			return std::make_unique<AddOperation>();
		}
		case OPERATION_TYPE::SUB: {
			return std::make_unique<SubOperation>();
		}
		default: {
			return nullptr;
		}
	}
}