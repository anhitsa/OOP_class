#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "CommandParser.hpp"
#include "OperationFactory.hpp"
#include "CommandExecutor.hpp"

class Controller 
{
public:
    Controller()= default;
    void run();
    
private:
    OperationFactory operationFactory;
    CommandExecutor commandExecutor; 
};

#endif // CONTROLLER_HPP
