#include "removecommand.h"

#include "../document/document.h"
#include "../document/documentmanager.h"
#include "../document/item.h"

#include <algorithm>

RemoveCommand::RemoveCommand(std::map<std::string, std::string> options)
    : options(options) {}

void RemoveCommand::execute()
{
    std::shared_ptr<Document> document = DocumentManager::getInstance().getDocument();
    auto itemId = std::stoi(options.at("item_id"));
    auto item = document->findItemById(itemId);
    if (itemId)
    {
        //TK: Do not dlete like this, use AddRemove action instead, Remove is also subject of Undo/Redo
        document->activeSlide->targets.erase(std::remove_if(document->activeSlide->targets.begin(), document->activeSlide->targets.end(),
                                                  [itemId](const std::shared_ptr<Target>& slideItem) {
                                                      return slideItem->getId() == itemId;
                                             }), document->activeSlide->targets.end());
        return;
    }

    auto slideId = std::stoi(options.at("slide_id"));
    auto slide = document->findSlideById<Target>(slideId);
    if (slide)
    {
        //TK: Do not dlete like this, use AddRemove action instead, Remove is also subject of Undo/Redo
        document->slides.erase(std::remove_if(document->slides.begin(), document->slides.end(),
                                             [slideId](const std::shared_ptr<Slide>& slide) {
                                                 return slide->getId() == slideId;
                               }), document->slides.end());
        return;
    }

    throw std::invalid_argument("Invalid ID");
}
