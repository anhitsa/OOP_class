#ifndef COMMAND_EXECUTOR_HPP
#define COMMAND_EXECUTOR_HPP

#include "Command.hpp"
#include "OperationFactory.hpp" 

class CommandExecutor 
{
    public:
        static double executeCommand(const Command& command, OperationFactory& factory); 
};

#endif // COMMAND_EXECUTOR_HPP
