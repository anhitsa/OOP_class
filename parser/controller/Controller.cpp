#include <sstream>

#include "Controller.hpp"

void Controller::run() 
{
    std::string input;
    OutputHandler::print_message("Enter a command: ");

    while (true) 
    {
        std::getline(std::cin, input);
        auto result = process_command(input);
        if(result.has_value())
        {
            OutputHandler::print_result(result.value());
        }
        OutputHandler::print_message("Enter a command: ");
    }
}

std::optional<double> Controller::process_command(std::string input)
{
    std::istringstream iss(input);
    auto command = CommandParser::parse_command(iss);
    auto result = command_executor.execute_command(command, operation_factory);
    return result;
}
