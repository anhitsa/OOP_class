#include "drawcommand.h"

DrawCommand::DrawCommand(std::map<std::string, std::string> options_, std::shared_ptr<Document> document,
                        std::shared_ptr<Renderer> renderer)
    : document(std::move(document)), renderer(std::move(renderer))
{
    options = std::move(options_);
}

void DrawCommand::execute()
{
    if (options.count("item_id"))
        drawItem();
    else
        drawSlide();
}

void DrawCommand::drawSlide() const
{
    std::shared_ptr<Slide> slide;
    if (options.count("slide_id"))
        slide = *(document->findSlideById(std::stoi(options.at("slide_id"))));
    slide = document->getActiveSlide();
    renderer->draw(slide);
}

void DrawCommand::drawItem() const
{
    std::shared_ptr<Item> item = *(document->getActiveSlide()->findItemById(std::stoi(options.at("item_id"))));
    renderer->draw(item);
}
