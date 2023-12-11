#include "displaycommand.h"
#include "../document/document.h"
#include "../document/documentmanager.h"

DisplayCommand::DisplayCommand(std::map<std::string, std::string> options)
    : options(options) {}

void DisplayCommand::execute()
{
    std::shared_ptr<Target> target = determineTarget();
    renderer.display(target);
}

std::shared_ptr<Target> DisplayCommand::determineTarget() //TK: code duplication
{
    std::shared_ptr<Document> document = DocumentManager::getInstance().getDocument();
    if (options.find("slide_id") != options.end())
    {
        int slideId = std::stoi(options.at("slide_id"));
        auto slide = document->findSlideById<Target>(slideId);
        if (slide)
            return slide;
    }
    if (options.find("item_id") != options.end())
    {
        int itemId = std::stoi(options.at("item_id"));
        auto item = document->findItemById(itemId);
        if (item)
            return item;
    }
    return document->activeSlide;
}

