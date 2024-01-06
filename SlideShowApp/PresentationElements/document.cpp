#include "document.h"

#include <memory>

Document::Document()
{
    const Slide::ID firstSlideId = 1;
    std::shared_ptr<Slide> slide = std::make_shared<Slide>(firstSlideId);
    add(slide);
    setActiveSlide(slide);
}

void Document::add(const std::shared_ptr<Slide>& slide)
{
    slides.push_back(slide);
}

void Document::remove(const std::shared_ptr<Slide>& target)
{
    auto it = std::find(slides.begin(), slides.end(), target);
    if (it != slides.end())
        slides.erase(it);
}

void Document::setActiveSlide(const std::shared_ptr<Slide>& slide)
{
    activeSlide = slide;
}

std::shared_ptr<Slide> Document::getActiveSlide() const
{
    return std::move(activeSlide);
}

Slide::ID Document::getNewSlideId() const
{
    return slides.size() + 1;
}

std::vector<std::shared_ptr<Slide>>::const_iterator Document::findSlideById(const Slide::ID& slideId) const
{
    return std::find_if(slides.begin(), slides.end(),
                        [slideId](const auto& slide) {
                            return slide->getId() == slideId;
                        });
}

std::vector<std::shared_ptr<Slide>> Document::getSlides() const
{
    return slides;
}
