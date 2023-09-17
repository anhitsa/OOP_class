#include "CommandExecutor.hpp"

std::optional<double> CommandExecutor::execute_command(const Command& command, OperationFactory& operation_factory) 
{
    static const std::unordered_map<std::string, std::function<void()>> command_actions = {
        {"quit", [&]() { execute_quit(); }},
        {"run", [&]() { execute_history_commands(operation_factory); }},
        {"create", [&]() { CommandHistory::save_in_history(command); }},
    }; 

    auto operation_type = determine_operation_type(command);
    auto it = command_actions.find(operation_type);
    if (it != command_actions.end()) 
    {
        it->second();
        return {}; 
    }

    std::unique_ptr<Operation> operation = operation_factory.create_operation(command);
    return operation->calculate(command.operands);
}

std::string CommandExecutor::determine_operation_type(Command command)
{
    if(command.save_in_history)
        return "create";
    return command.operation_type;
}

void CommandExecutor::execute_history_commands(OperationFactory& operation_factory)
{
    auto command_count = size(CommandHistory::history);
    for(auto i = 0; i < command_count; i++)
    {
        CommandHistory::history[0].save_in_history = false;
        OutputHandler::print_command(CommandHistory::history[0]);
        auto result = execute_command(CommandHistory::history[0], operation_factory);
        OutputHandler::print_result(result.value());
        CommandHistory::remove_from_history(CommandHistory::history[0]);
    }
}

void CommandExecutor::execute_quit()
{
    std::cout << "Quitting ... " << std::endl;
    exit(0);
}