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

void Document::setActiveSlide(const std::shared_ptr<Target>& slide)
{
    activeSlide = std::dynamic_pointer_cast<Slide>(slide);
}

std::shared_ptr<Target> Document::findItemById(const int& itemId) const
{
    for (const auto& slide : slides)
    {
        auto item = slide->findItemById(itemId);
        if (item)
            return item;
    }
    return nullptr;
}
