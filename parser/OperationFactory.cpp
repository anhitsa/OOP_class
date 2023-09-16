#include "OperationFactory.hpp"
#include "AdditionOperation.hpp"
#include "SubtractionOperation.hpp"
#include "MultiplicationOperation.hpp"
#include "DivisionOperation.hpp"
#include "PowOperation.hpp"
#include "SqrtOperation.hpp"

OperationFactory::OperationFactory() 
{
    operations["add"] = []() { return std::make_unique<AdditionOperation>(); };
    operations["sub"] = []() { return std::make_unique<SubtractionOperation>(); };
    operations["mul"] = []() { return std::make_unique<MultiplicationOperation>(); };
    operations["div"] = []() { return std::make_unique<DivisionOperation>(); };
    operations["pow"] = []() { return std::make_unique<PowOperation>(); };
    operations["sqrt"] = []() { return std::make_unique<SqrtOperation>(); };
}

std::unique_ptr<Operation> OperationFactory::createOperation(const Command& command) 
{
    auto it = operations.find(command.operationType);
    if (it != operations.end()) 
    {
        return it->second();
    }
    throw std::invalid_argument("Not a valid operationType");
}
