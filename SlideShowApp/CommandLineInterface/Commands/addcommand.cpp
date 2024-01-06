#include "addcommand.h"

AddCommand::AddCommand(std::map<std::string, std::string> options_, std::shared_ptr<Document> document, std::shared_ptr<ActionManager> actionManager)
    : document(std::move(document)), actionManager(std::move(actionManager))
{
    options = std::move(options_);
}

void AddCommand::execute()
{
    if (options.find("item") != options.end())
        addItem();
    else if (options.find("slide") != options.end())
        addSlide();
}

void AddCommand::addItem()
{
    std::shared_ptr<Item> item = createItem(document->getActiveSlide()->getNewItemId());
    std::shared_ptr<Slide> slide;
    if (options.count("slide_id"))
        slide = *(document->findSlideById(std::stoi(options.at("slide_id"))));
    else if (document->getActiveSlide())
        slide = document->getActiveSlide();
    else
    {
        slide = std::make_shared<Slide>(document->getNewSlideId());
        document->add(slide);
        document->setActiveSlide(slide);
    }
    std::shared_ptr<CommandAction> action = std::make_shared<AddItemAction>(item, slide);
    actionManager->do_(action);
}

void AddCommand::addSlide()
{
    std::shared_ptr<Slide> slide = std::make_shared<Slide>(document->getNewSlideId());
    document->setActiveSlide(slide);
    std::shared_ptr<CommandAction> action = std::make_shared<AddSlideAction>(slide, document);
    actionManager->do_(action);
}

std::shared_ptr<Item> AddCommand::createItem(const Item::ID itemId)
{
    std::string kind = options.at("item");
    Coord top_left = Coord(options.at("top_left"));
    std::string color = options.count("color") > 0 ? options.at("color") : "black";
    std::string text = options.count("text") > 0 ? options.at("text") : "";

    if (options.count("bottom_right"))
    {
        Coord bottom_right = Coord(options["bottom_right"]);

        if (options.count("height") && options.count("width"))
                return std::make_shared<Item>(kind, RectangleGeometry(top_left, bottom_right, std::stoi(options["height"]), std::stoi(options["width"])), itemId, color, text);

        return std::make_shared<Item>(kind, RectangleGeometry(top_left, bottom_right), itemId, color, text);
    }
    if (options.count("height") > 0 && options.count("width") == 0)
        return std::make_shared<Item>(kind, RectangleGeometry(top_left, std::stoi(options["height"])), itemId, color, text);
    else if (options.count("width") > 0 && options.count("height") == 0)
        return std::make_shared<Item>(kind, RectangleGeometry(top_left, std::stoi(options["width"])), itemId, color, text);
    else if (options.count("height") && options.count("width"))
        return std::make_shared<Item>(kind, RectangleGeometry(top_left, std::stoi(options["height"]), std::stoi(options["width"])), itemId, color, text);

}
