#include "CommandExecutor.hpp"
#include "Operation.hpp"

#include <iostream>
#include <stdexcept>

double CommandExecutor::executeCommand(const Command& command, OperationFactory& operationFactory) 
{
    std::unique_ptr<Operation> operation = operationFactory.createOperation(command);
    return operation->execute(command.operands);
}
