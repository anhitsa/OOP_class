#include "displaycommand.h"
#include "../../PresentationElements/document.h"

DisplayCommand::DisplayCommand(std::map<std::string, std::string> options_, std::shared_ptr<Document> document,
                               std::shared_ptr<Renderer> renderer)
    : document(std::move(document)), renderer(std::move(renderer))
{
    options = std::move(options_);
}

void DisplayCommand::execute()
{
    if (!options.count("item_id"))
        displaySlide();
    else
        displayItem();
}

void DisplayCommand::displayItem()
{
    int itemId = std::stoi(options.at("item_id"));
    auto item = *(document->getActiveSlide()->findItemById(itemId));
    std::string itemInformation = item->getInfo();
    renderer->display(itemInformation);
}

void DisplayCommand::displaySlide()
{
    std::shared_ptr<Slide> slide;
    if(options.count("slide_id"))
    {
        int slideId = std::stoi(options.at("slide_id"));
        slide = *(document->findSlideById(slideId));
    }
    else
        slide = document->getActiveSlide();
    std::string slideInformation = slide->getInfo();
    renderer->display(slideInformation);
}
