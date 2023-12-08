#include "commandfactory.h"

CommandFactory::CommandFactory()
{
    commands["add"] = [this](const std::unordered_map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return createAddCommand(options);
    };
    commands["change"] = [this](const std::unordered_map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return createChangeCommand(options);
    };
    commands["display"] = [this](const std::unordered_map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return createDisplayCommand(options);
    };
    commands["exit"] = [this](const std::unordered_map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return createExitCommand(options);
    };
    commands["remove"] = [this](const std::unordered_map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return createRemoveCommand(options);
    };
    commands["save"] = [this](const std::unordered_map<std::string, std::string>& options) -> std::unique_ptr<Command> {
        return createSaveCommand(options);
    };
}

std::unique_ptr<Command> CommandFactory::createCommand(const std::string command_name, std::map<std::string, std::optional<std::string>> options)
{
    auto it = commands.find(command_name);
    if (it != commands.end())
        return it->second(options);
    throw std::invalid_argument("Not a valid command name");
}

std::shared_ptr<Target> CommandFactory::resolveSlide(const std::unordered_map<std::string, std::string>& options, Document& document) {
    if (options.count("slide_id")) {
        ID slideId = options.at("slide_id");
        return document.findSlideById(slideId);
    } else {
        return document.getActiveSlide() ? document.getActiveSlide() : document.createNewSlide();
    }
}

std::shared_ptr<Container> CommandFactory::createContainer(const std::shared_ptr<Target>& target, Document& document, const std::unordered_map<std::string, std::string>& options) {
    if (std::dynamic_pointer_cast<Item>(target))
    {
        if (options.count("slide_id"))
        {
            ID slideId = options.at("slide_id");
            return document.findSlideById(slideId);
        }
        else
            return document.getActiveSlide() ? document.getActiveSlide() : document.createNewSlide();
    }

    else if (std::dynamic_pointer_cast<Slide>(target))
        return std::dynamic_pointer_cast<Container>(std::make_shared<Document>(document));

}

std::unique_ptr<Command> CommandFactory::createAddCommand(const std::unordered_map<std::string, std::string>& options)
{
    std::shared_ptr<Target> target = createTarget(options);
    std::shared_ptr<Container> container = createContainer(target, document, options);

    if (auto slide = std::dynamic_pointer_cast<Slide>(container))
        document.setActiveSlide(slide);

    return std::make_unique<AddCommand>(target, container);
}

std::unique_ptr<Command> CommandFactory::createChangeCommand(const std::unordered_map<std::string, std::string>& options)
{

}

std::unique_ptr<Command> CommandFactory::createDisplayCommand(const std::unordered_map<std::string, std::string>& options)
{

}

std::unique_ptr<Command> CommandFactory::createExitCommand(const std::unordered_map<std::string, std::string>& options)
{

}

std::unique_ptr<Command> CommandFactory::createRemoveCommand(const std::unordered_map<std::string, std::string>& options)
{

}

std::unique_ptr<Command> CommandFactory::createSaveCommand(const std::unordered_map<std::string, std::string>& options)
{

}

std::shared_ptr<Target> CommandFactory::createTarget(const std::unordered_map<std::string, std::string>& options)
{
    if (options.find("--item") != options.end())
        return createItem(options);
    else if (options.find("--slide") != options.end())
        return std::make_shared<Slide>();;
    throw std::invalid_argument("Unknown target type");
}

std::shared_ptr<Target> CommandFactory::createItem(const std::unordered_map<std::string, std::string>& options)
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

