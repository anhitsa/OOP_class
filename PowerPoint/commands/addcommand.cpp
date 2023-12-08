#include "addcommand.h"
#include "../actions/commandaction.h"
#include "../actions/addremoveaction.h"

#include <memory>

AddCommand::AddCommand(std::shared_ptr<Target> target)
    : target(target) {}

void AddCommand::execute()
{
    std::shared_ptr<Container> container = determineContainer();
    std::shared_ptr<CommandAction> action = std::make_shared<AddRemoveAction>(target, container);
    action->execute();
    commandHistory.push(action);
}
