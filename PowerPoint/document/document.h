#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "container.h"
#include "slide.h"

#include <vector>

class Document : public Container
{
public:
    Document() = default;

    void addTarget(const std::shared_ptr<Target>&) override;
    void removeTarget(const std::shared_ptr<Target>&) override;

    void setActiveSlide(const std::shared_ptr<Target>& slide)
    {
        activeSlide = std::dynamic_pointer_cast<Slide>(slide);
    }

    std::shared_ptr<Target> getActiveSlide() const
    {
        return activeSlide;
    }

    std::shared_ptr<Target> findSlideById(const ID& slideId) const {
        auto it = std::find_if(slides.begin(), slides.end(),
                               [slideId](const auto& slide) {
                                   return slide->getID() == slideId;
                               });

        return (it != slides.end()) ? *it : nullptr;
    }

    std::shared_ptr<Target> createNewSlide() {
        std::shared_ptr<Target> newSlide = std::make_shared<Slide>();
        slides.push_back(newSlide);
        setActiveSlide(newSlide);
        return newSlide;
    }

private:
    std::vector<std::shared_ptr<Target>> slides;
    std::shared_ptr<Slide> activeSlide;

};
#endif // DOCUMENT_H
