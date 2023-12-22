#include "changecommand.h"

ChangeCommand::ChangeCommand(std::map<std::string, std::string> options_, std::shared_ptr<Document> document, std::shared_ptr<ActionManager> actionManager)
    : document(std::move(document)), actionManager(actionManager)
{
    options = std::move(options_);
}

void ChangeCommand::execute()
{
    std::shared_ptr<Item> item = determineItem();
    std::shared_ptr<CommandAction> action = std::make_shared<ChangeAction>(item, options);
    actionManager->do_(action);
}

std::shared_ptr<Item> ChangeCommand::determineItem()
{
    if (options.find("item_id") != options.end())
    {
        int itemId = std::stoi(options.at("item_id"));
        auto item = document->findItemById(itemId);
        if (item)
        {
            options.erase("item_id");
            return std::static_pointer_cast<Item>(item);
        }
    }

    throw std::invalid_argument("--id option is required for the Change command");
}
