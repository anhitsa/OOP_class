#ifndef OPERATION_FACTORY_HPP
#define OPERATION_FACTORY_HPP

#include <functional> // std::function
#include <map>
#include <numeric> // std::accumulate
#include <stdexcept> // std::invalid_argument
#include <string>
#include <memory> // std::make_unique

#include "Command.hpp"
#include "Operation.hpp"

class OperationFactory 
{
public:
    OperationFactory();
    std::unique_ptr<Operation> createOperation(const Command& command);

private:
    std::map<std::string, std::function<std::unique_ptr<Operation>()>> operations;
};


#endif // OPERATION_FACTORY_HPP
