#include "../actions/changeaction.h"
#include "changecommand.h"
#include "../document/document.h"
#include "../document/documentmanager.h"
#include "../commandHistory/commandhistory.h"

ChangeCommand::ChangeCommand(std::map<std::string, std::string> options)
    : options(options) {}

void ChangeCommand::execute()
{
    CommandHistory& commandHistory = CommandHistory::getInstance();
    std::shared_ptr<Target> target = determineTarget();
    std::shared_ptr<CommandAction> action = std::make_shared<ChangeAction>(target, options);
    action->execute();
    commandHistory.push(action);
}

std::shared_ptr<Target> ChangeCommand::determineTarget()
{
    std::shared_ptr<Document> document = DocumentManager::getInstance().getDocument();
    if (options.find("slide_id") != options.end())
    {
        int slideId = std::stoi(options.at("slide_id"));
        auto slide = document->findSlideById<Target>(slideId);

        if (slide)
        {
            options.erase("slide_id");
            return slide;
        }
    }
    if (options.find("item_id") != options.end())
    {
        int itemId = std::stoi(options.at("item_id"));
        auto item = document->findItemById(itemId);
        if (item)
        {
            options.erase("item_id");
            return item;
        }
    }

    throw std::invalid_argument("--id option is required for the Change command");
}
