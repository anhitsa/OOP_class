#include "addcommand.h"
#include "../actions/commandaction.h"
#include "../actions/addremoveaction.h"
#include "../document/document.h"
#include "../document/slide.h"

#include <memory>

AddCommand::AddCommand(std::unordered_map<std::string, std::string> options)
    : options(options) {}

void AddCommand::execute()
{
    Document& document = Document::getInstance();
    std::shared_ptr<Target> target = createTarget();
    std::shared_ptr<Container> container = createContainer(target);

    if (auto slide = std::dynamic_pointer_cast<Slide>(container))
        document.setActiveSlide(slide);

    std::shared_ptr<CommandAction> action = std::make_shared<AddRemoveAction>(target, container);
    action->execute();
    commandHistory.push(action);
}

std::shared_ptr<Target> AddCommand::createTarget()
{
    if (options.find("--item") != options.end())
        return createItem(options);
    else if (options.find("--slide") != options.end())
        return std::make_shared<Slide>();;
    throw std::invalid_argument("Unknown target type");
}

std::shared_ptr<Container> AddCommand::createContainer(const std::shared_ptr<Target>& target) {
    Document& document = Document::getInstance();
    if (std::dynamic_pointer_cast<Item>(target))
    {
        if (options.count("slide_id"))
        {
            int slideId = options.at("slide_id");
            return document.findSlideById(slideId);
        }
        else
            return document.getActiveSlide() ? document.getActiveSlide() : document.createNewSlide();
    }

    else if (std::dynamic_pointer_cast<Slide>(target))
        return std::dynamic_pointer_cast<Container>(std::make_shared<Document>(document));
}

std::shared_ptr<Target> AddCommand::createItem()
{
    std::string kind = options.at("kind");
    Coord top_left = Coord(options.at("top_left"));
    Coord bottom_right = (options.find("bottom_right") != options.end()) ? Coord(options.at("bottom_right")) : Coord();
    Item::Length height = (options.find("height") != options.end()) ? Length(options.at("height")) : Length();
    Item::Length width = (options.find("width") != options.end()) ? Length(options.at("width")) : Length();

    if (options.find("bottom_right") != options.end() && options.find("height") != options.end() && options.find("width") != options.end())
        return std::make_shared<Item>(kind, top_left, bottom_right, height, width, id);
    else if (options.find("bottom_right") != options.end())
        return std::make_shared<Item>(kind, top_left, bottom_right, id);
    else
        return std::make_shared<Item>(kind, top_left, height, width, id);
}
