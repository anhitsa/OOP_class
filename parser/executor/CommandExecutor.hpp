#ifndef COMMAND_EXECUTOR_HPP
#define COMMAND_EXECUTOR_HPP

#include "../commands/Command.hpp"
#include "../commands/CommandHistory.hpp"
#include "../factory/OperationFactory.hpp" 
#include "../OutputHandler.hpp"

#include <optional>
#include <stdexcept>

class CommandExecutor 
{
    public:
        std::optional<double> execute_command(const Command& command, OperationFactory&); 
        void execute_history_commands(OperationFactory&);
        void execute_quit();

    private:
        std::string determine_operation_type(Command command);
};

#endif // COMMAND_EXECUTOR_HPP
