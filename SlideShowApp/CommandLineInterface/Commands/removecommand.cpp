#include "removecommand.h"

#include <algorithm>

RemoveCommand::RemoveCommand(std::map<std::string, std::string> options_, std::shared_ptr<Document> document, std::shared_ptr<ActionManager> actionManager)
    : document(std::move(document)), actionManager(std::move(actionManager))
{
    options = std::move(options_);
}

void RemoveCommand::execute()
{
    if (options.count("item_id"))
        removeItem();
    else if (options.count("slide_id"))
        removeSlide();
}

void RemoveCommand::removeItem()
{
    std::shared_ptr<Item> item = *(document->getActiveSlide()->findItemById(std::stoi(options.at("item_id"))));
    std::shared_ptr<Slide> slide;

    if (options.count("slide_id"))
    {
        int slideId = std::stoi(options.at("slide_id"));
        slide = *(document->findSlideById(slideId));
    }
    else if (document->getActiveSlide())
        slide = document->getActiveSlide();

    std::shared_ptr<CommandAction> action = std::make_shared<RemoveItemAction>(item, slide);
    actionManager->do_(action);
}

void RemoveCommand::removeSlide()
{
    std::shared_ptr<Slide> slide;
    if (options.count("slide_id"))
        slide = *(document->findSlideById(std::stoi(options.at("slide_id"))));
    else
        slide = document->getActiveSlide();
    std::shared_ptr<CommandAction> action = std::make_shared<RemoveSlideAction>(slide, document);
    actionManager->do_(action);
}


