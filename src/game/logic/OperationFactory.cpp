#include "OperationFactory.h"

std::unique_ptr<Operation> OperationFactory::createOperation(OPERATION_TYPE operation) {
    switch(operation) {
        case OPERATION_TYPE::MOV:
            return std::make_unique<MovOperation>();
        case OPERATION_TYPE::ADD:
            //return std::make_unique<AddOperation>();
        // Add other operations here
        default:
            return nullptr;
    }
}