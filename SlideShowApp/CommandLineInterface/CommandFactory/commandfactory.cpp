#include "commandfactory.h"

#include "../Commands/addcommand.h"
#include "../Commands/changecommand.h"
#include "../Commands/displaycommand.h"
#include "../Commands/drawcommand.h"
#include "../Commands/exitcommand.h"
#include "../Commands/removecommand.h"
#include "../Commands/savecommand.h"

CommandFactory::CommandFactory(std::shared_ptr<Document> document, std::shared_ptr<Renderer> renderer, std::shared_ptr<Serializer> serializer, std::shared_ptr<ActionManager> actionManager)
{
    commands["add"] = [this, document, actionManager](const std::map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return std::make_unique<AddCommand>(options, document, actionManager);
    };
    commands["change"] = [this, document, actionManager](const std::map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return std::make_unique<ChangeCommand>(options, document, actionManager);
    };
    commands["display"] = [this, document, renderer](const std::map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return std::make_unique<DisplayCommand>(options, document, renderer);
    };
    commands["draw"] = [this, document, renderer](const std::map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return std::make_unique<DrawCommand>(options, document, renderer);
    };
    commands["exit"] = [this](const std::map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return std::make_unique<ExitCommand>(options);
    };
    commands["remove"] = [this, document, actionManager](const std::map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return std::make_unique<RemoveCommand>(options, document, actionManager);
    };
    commands["save"] = [this, document, serializer](const std::map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return std::make_unique<SaveCommand>(options, document, serializer);
    };
}

std::unique_ptr<Command> CommandFactory::createCommand(const std::string command_name, std::map<std::string, std::string> options)
{
    auto it = commands.find(command_name);
    if (it != commands.end())
        return it->second(options);
    throw std::invalid_argument("Not a valid command name");
}
