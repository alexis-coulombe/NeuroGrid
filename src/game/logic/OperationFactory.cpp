#include "OperationFactory.h"
#include "operators/MovOperation.h"
#include "operators/NopOperation.h"
#include "operators/AddOperation.h"
#include "operators/SubOperation.h"
#include "operators/JmpOperation.h"
#include "operators/JmtOperation.h"
#include "operators/JmfOperation.h"
#include "operators/TeqOperation.h"
#include "operators/TneOperation.h"
#include "operators/TltOperation.h"
#include "operators/TgtOperation.h"
#include "operators/TgeOperation.h"
#include "operators/TleOperation.h"

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
		case OPERATION_TYPE::JMP: {
			return std::make_unique<JmpOperation>();
		}
		case OPERATION_TYPE::JMT: {
			return std::make_unique<JmtOperation>();
		}
		case OPERATION_TYPE::JMF: {
			return std::make_unique<JmfOperation>();
		}
		case OPERATION_TYPE::TEQ: {
			return std::make_unique<TeqOperation>();
		}
		case OPERATION_TYPE::TNE: {
			return std::make_unique<TneOperation>();
		}
		case OPERATION_TYPE::TLE: {
			return std::make_unique<TleOperation>();
		}
		case OPERATION_TYPE::TGE: {
			return std::make_unique<TgeOperation>();
		}
		case OPERATION_TYPE::TGT: {
			return std::make_unique<TgtOperation>();
		}
		case OPERATION_TYPE::TLT: {
			return std::make_unique<TltOperation>();
		}
		default: {
			return nullptr;
		}
	}
}