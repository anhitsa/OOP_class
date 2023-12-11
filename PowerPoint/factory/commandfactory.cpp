#include "commandfactory.h"

CommandFactory::CommandFactory()
{
    //TK: Since here you have individual creators for each command, you can pass all necessary thing to the command via its constructor
    //TK: i.e  pointers of Document, Director & etc could be passed to the Factory by Application itself and Factory could bass it to specific commands 
    commands["add"] = [this](const std::map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return std::make_unique<AddCommand>(options);
    };
    commands["change"] = [this](const std::map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return std::make_unique<ChangeCommand>(options);
    };
    commands["display"] = [this](const std::map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return std::make_unique<DisplayCommand>(options);
    };
    commands["draw"] = [this](const std::map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return std::make_unique<DrawCommand>(options);
    };
    commands["exit"] = [this](const std::map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return std::make_unique<ExitCommand>(options);
    };
    commands["remove"] = [this](const std::map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return std::make_unique<RemoveCommand>(options);
    };
    commands["save"] = [this](const std::map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return std::make_unique<SaveCommand>(options);
    };
}

std::unique_ptr<Command> CommandFactory::createCommand(const std::string command_name, std::map<std::string, std::string> options)
{
    auto it = commands.find(command_name);
    if (it != commands.end())
        return it->second(options);
    throw std::invalid_argument("Not a valid command name");
}
