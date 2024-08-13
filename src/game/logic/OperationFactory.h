#ifndef ASM_OPERATIONFACTORY_H_
#define ASM_OPERATIONFACTORY_H_

#include <memory>
#include "Operator.h"
#include "operators/OperationType.h"

class OperationFactory {
    public:  
        std::unique_ptr<Operation> createOperation(OPERATION_TYPE operation);
}

#endif