#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../command_parser/CommandParser.hpp"
#include "../commands/CommandHistory.hpp"
#include "../executor/CommandExecutor.hpp"
#include "../factory/OperationFactory.hpp"
#include "../OutputHandler.hpp"

#include <map>
#include <optional>
#include <vector>

class Controller 
{
public:
    Controller() {}
    void run();

private:
    std::optional<double> process_command(std::string);

private:
    CommandExecutor command_executor;
    OperationFactory operation_factory;

};

#endif // CONTROLLER_HPP
