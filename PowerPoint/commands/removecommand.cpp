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
    int targetId = std::stoi(options.at("id"));
    auto item = document->findItemById(targetId);
    if (item)
    {
        document->activeSlide->targets.erase(std::remove_if(document->activeSlide->targets.begin(), document->activeSlide->targets.end(),
                                                  [targetId](const std::shared_ptr<Target>& slideItem) {
                                                      return slideItem->getId() == targetId;
                                             }), document->activeSlide->targets.end());
        return;
    }

    auto slide = document->findSlideById<Target>(targetId);
    if (slide)
    {
        document->slides.erase(std::remove_if(document->slides.begin(), document->slides.end(),
                                             [targetId](const std::shared_ptr<Slide>& slide) {
                                                 return slide->getId() == targetId;
                               }), document->slides.end());
        return;
    }

    throw std::invalid_argument("Invalid ID");
}
