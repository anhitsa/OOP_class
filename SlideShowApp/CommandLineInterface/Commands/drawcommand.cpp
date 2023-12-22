#include "drawcommand.h"

DrawCommand::DrawCommand(std::map<std::string, std::string> options_, std::shared_ptr<Document> document,
                        std::shared_ptr<Renderer> renderer)
    : document(std::move(document)), renderer(std::move(renderer))
{
    options = std::move(options_);
}

void DrawCommand::execute()
{
    std::shared_ptr<Target> target = determineTarget();
    renderer->draw(target);
}

std::shared_ptr<Target> DrawCommand::determineTarget() //TK: code duplication
{
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
