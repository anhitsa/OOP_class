#include "addcommand.h"

int AddCommand::slideIdCount = 0;
int AddCommand::itemIdCount = 0;

AddCommand::AddCommand(std::map<std::string, std::string> options_, std::shared_ptr<Document> document, std::shared_ptr<ActionManager> actionManager)
    : document(std::move(document)), actionManager(std::move(actionManager))
{
    options = std::move(options_);
}

void AddCommand::execute()
{
    std::shared_ptr<Target> target = createTarget();
    std::shared_ptr<Container<Target>> container = determineContainer(target);

    if (auto slide = std::dynamic_pointer_cast<Slide>(container))
        document->setActiveSlide(slide);

    std::shared_ptr<CommandAction> action = std::make_shared<AddAction>(target, container);
    actionManager->do_(action);
}

std::shared_ptr<Target> AddCommand::createTarget()
{
    if (options.find("item") != options.end())
        return createItem();
    else if (options.find("slide") != options.end())
        return std::make_shared<Slide>();;
    throw std::invalid_argument("Unknown target type");
}

std::shared_ptr<Container<Target>> AddCommand::determineContainer(const std::shared_ptr<Target>& target) {
    if (std::dynamic_pointer_cast<Item>(target))
    {
        if (options.count("slide_id"))
        {
            int slideId = std::stoi(options.at("slide_id"));
            return document->findSlideById<Container<Target>>(slideId);
        }
        else
            if (document->getActiveSlide())
                return std::dynamic_pointer_cast<Container<Target>>(document->getActiveSlide());
            else
                return document->createNewSlide<Container<Target>>();
    }

    else if (std::dynamic_pointer_cast<Slide>(target))
        return std::dynamic_pointer_cast<Container<Target>>(document);
}

std::shared_ptr<Target> AddCommand::createItem()
{
    itemIdCount++;
    std::string kind = options.at("item");
    Coord top_left = Coord(options.at("top_left"));
    Coord bottom_right = (options.find("bottom_right") != options.end()) ? Coord(options.at("bottom_right")) : Coord();
    int height = (options.find("height") != options.end()) ? std::stoi(options.at("height")) : 0;
    int width = (options.find("width") != options.end()) ? std::stoi(options.at("width")) : 0;

    if (options.find("bottom_right") != options.end() && options.find("height") != options.end() && options.find("width") != options.end())
        return std::make_shared<Item>(kind, Rectangle(top_left, bottom_right, height, width), itemIdCount);
    else if (options.find("bottom_right") != options.end())
        return std::make_shared<Item>(kind, Rectangle(top_left, bottom_right), itemIdCount);
    else
        return std::make_shared<Item>(kind, Rectangle(top_left, height, width), itemIdCount);
}
