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
    void setActiveSlide(const std::shared_ptr<Target>& slide);
    std::shared_ptr<Target> findItemById(const int& itemId) const;
    std::shared_ptr<Target> createNewSlide();

    template <typename TargetType>
    std::shared_ptr<TargetType> findSlideById(const int& slideId) const {
        auto it = std::find_if(slides.begin(), slides.end(),
                               [slideId](const auto& slide) {
                                   return slide->getId() == slideId;
                               });

        return (it != slides.end()) ? std::dynamic_pointer_cast<TargetType>(*it) : nullptr;
    }

    template <typename TargetType>
    std::shared_ptr<TargetType> getActiveSlide() const{
        return std::dynamic_pointer_cast<TargetType>(activeSlide);
    }

    template <typename TargetType>
    std::shared_ptr<TargetType> createNewSlide(){
        std::shared_ptr<TargetType> newSlide = std::make_shared<Slide>();
        slides.push_back(std::dynamic_pointer_cast<Slide>(newSlide));
        setActiveSlide(std::dynamic_pointer_cast<Slide>(newSlide));
        return newSlide;
    }


public:
    std::vector<std::shared_ptr<Slide>> slides;
    std::shared_ptr<Slide> activeSlide;

};
#endif // DOCUMENT_H
