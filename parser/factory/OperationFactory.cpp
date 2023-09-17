#include "OperationFactory.hpp"
#include "../operations/AdditionOperation.hpp"
#include "../operations/SubtractionOperation.hpp"
#include "../operations/MultiplicationOperation.hpp"
#include "../operations/DivisionOperation.hpp"
#include "../operations/PowOperation.hpp"
#include "../operations/SqrtOperation.hpp"

OperationFactory::OperationFactory() 
{
    operations["add"] = []() { return std::make_unique<AdditionOperation>(); };
    operations["sub"] = []() { return std::make_unique<SubtractionOperation>(); };
    operations["mul"] = []() { return std::make_unique<MultiplicationOperation>(); };
    operations["div"] = []() { return std::make_unique<DivisionOperation>(); };
    operations["pow"] = []() { return std::make_unique<PowOperation>(); };
    operations["sqrt"] = []() { return std::make_unique<SqrtOperation>(); };
}

std::unique_ptr<Operation> OperationFactory::create_operation(const Command& command) 
{
    auto it = operations.find(command.operation_type);
    if (it != operations.end()) 
    {
        return it->second();
    }
    throw std::invalid_argument("Not a valid operationType");
}
