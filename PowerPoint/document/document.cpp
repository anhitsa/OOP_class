#include "document.h"
#include "target.h"
#include "slide.h"

#include <memory>

void Document::addTarget(const std::shared_ptr<Target>& target)
{
    slides.push_back(std::dynamic_pointer_cast<Slide>(target));
}

void Document::removeTarget(const std::shared_ptr<Target>& target)
{
    auto it = std::find(slides.begin(), slides.end(), target);
    if (it != slides.end())
        slides.erase(it);
}

static Document& Document::getInstance()
{
    static Document instance;
    return instance;
}

void Document::setActiveSlide(const std::shared_ptr<Target>& slide)
{
    activeSlide = std::dynamic_pointer_cast<Slide>(slide);
}

std::shared_ptr<Target> Document::getActiveSlide() const
{
    return activeSlide;
}

std::shared_ptr<Target> Document::findSlideById(const ID& slideId) const
{
    auto it = std::find_if(slides.begin(), slides.end(),
                           [slideId](const auto& slide) {
                               return slide->getID() == slideId;
                           });

    return (it != slides.end()) ? *it : nullptr;
}

std::shared_ptr<Target> Document::findItemById(const ID& itemId) const
{
    for (const auto& slide : slides)
    {
        auto item = slide->findItemById(itemId);
        if (item)
            return item;
    }
    return nullptr;
}

std::shared_ptr<Target> Document::createNewSlide()
{
    std::shared_ptr<Target> newSlide = std::make_shared<Slide>();
    slides.push_back(newSlide);
    setActiveSlide(newSlide);
    return newSlide;
}
