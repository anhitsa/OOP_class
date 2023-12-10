#include "addcommand.h"
#include "../actions/commandaction.h"
#include "../actions/addremoveaction.h"
#include "../commandHistory/commandhistory.h"
#include "../document/document.h"
#include "../document/documentmanager.h"
#include "../document/slide.h"

#include <memory>

int AddCommand::slideIdCount = 0;
int AddCommand::itemIdCount = 0;

AddCommand::AddCommand(std::map<std::string, std::string> options)
    : options(options) {}

void AddCommand::execute()
{
    std::shared_ptr<Document> document = DocumentManager::getInstance().getDocument();
    CommandHistory& commandHistory = CommandHistory::getInstance();
    std::shared_ptr<Target> target = createTarget();
    std::shared_ptr<Container> container = createContainer(target);

    if (auto slide = std::dynamic_pointer_cast<Slide>(container))
        document->setActiveSlide(slide);

    std::shared_ptr<CommandAction> action = std::make_shared<AddRemoveAction>(target, container);
    action->execute();
    commandHistory.push(action);
}

std::shared_ptr<Target> AddCommand::createTarget()
{
    if (options.find("item") != options.end())
        return createItem();
    else if (options.find("slide") != options.end())
        return std::make_shared<Slide>();;
    throw std::invalid_argument("Unknown target type");
}

std::shared_ptr<Container> AddCommand::createContainer(const std::shared_ptr<Target>& target) {
    std::shared_ptr<Document> document = DocumentManager::getInstance().getDocument();
    if (std::dynamic_pointer_cast<Item>(target))
    {
        if (options.count("slide_id"))
        {
            int slideId = std::stoi(options.at("slide_id"));
            return document->findSlideById<Container>(slideId);
        }
        else
            return document->getActiveSlide<Container>() ? document->getActiveSlide<Container>() : document->createNewSlide<Container>();
    }

    else if (std::dynamic_pointer_cast<Slide>(target))
        return std::dynamic_pointer_cast<Container>(document);
}

std::shared_ptr<Target> AddCommand::createItem()
{
    itemIdCount++;
    std::string kind = options.at("kind");
    Coord top_left = Coord(options.at("top_left"));
    Coord bottom_right = (options.find("bottom_right") != options.end()) ? Coord(options.at("bottom_right")) : Coord();
    int height = (options.find("height") != options.end()) ? std::stoi(options.at("height")) : 0;
    int width = (options.find("width") != options.end()) ? std::stoi(options.at("width")) : 0;

    if (options.find("bottom_right") != options.end() && options.find("height") != options.end() && options.find("width") != options.end())
        return std::make_shared<Item>(kind, top_left, bottom_right, height, width, itemIdCount);
    else if (options.find("bottom_right") != options.end())
        return std::make_shared<Item>(kind, top_left, bottom_right, itemIdCount);
    else
        return std::make_shared<Item>(kind, top_left, height, width, itemIdCount);
}
