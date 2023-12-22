#include "removecommand.h"

#include <algorithm>

RemoveCommand::RemoveCommand(std::map<std::string, std::string> options_, std::shared_ptr<Document> document, std::shared_ptr<ActionManager> actionManager)
    : document(std::move(document)), actionManager(std::move(actionManager))
{
    options = std::move(options_);
}

void RemoveCommand::execute()
{
    std::shared_ptr<Target> target = determineTarget();
    std::shared_ptr<Container<Target>> container = determineContainer(target);

    if (auto slide = std::dynamic_pointer_cast<Slide>(container))
        document->setActiveSlide(slide);

    std::shared_ptr<CommandAction> action = std::make_shared<RemoveAction>(target, container);
    actionManager->do_(action);
}

std::shared_ptr<Target> RemoveCommand::determineTarget()
{
    int itemId = std::stoi(options.at("item_id"));
    if (itemId)
        return document->findItemById(itemId);
    int slideId = std::stoi(options.at("item_id"));
    if (slideId)
        return document->findSlideById<Target>(slideId);
    throw std::invalid_argument("Unknown target type");
}

std::shared_ptr<Container<Target>> RemoveCommand::determineContainer(const std::shared_ptr<Target>& target)
{
    if (std::dynamic_pointer_cast<Item>(target) && options.count("item_id"))
    {
        if (options.count("slide_id"))
        {
            int slideId = std::stoi(options.at("slide_id"));
            return document->findSlideById<Container<Target>>(slideId);
        }
        else if (document->getActiveSlide())
                return std::dynamic_pointer_cast<Container<Target>>(document->getActiveSlide());
    }

    else if (std::dynamic_pointer_cast<Slide>(target))
        return std::dynamic_pointer_cast<Container<Target>>(document);
}

