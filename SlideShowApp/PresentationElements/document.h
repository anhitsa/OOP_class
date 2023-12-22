#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "container.h"
#include "slide.h"

#include <vector>

class Document : public Container<Slide>
{
public:
    Document() = default;
    //TK: I do not understand for what this Target is needed for
    //TK: I can imagine documents intercase more simpler: add(Slide, position), remove(index), get(index), count(), iterators: begin(), end()
    void add(const std::shared_ptr<Slide>&) override;
    void remove(const std::shared_ptr<Slide>&) override;
    //TK: I doubt that active slide belongs to the document, it is more editor/viewer's competency
    void setActiveSlide(const std::shared_ptr<Target>& slide);
    std::shared_ptr<Target> findItemById(const int& itemId) const;
    //TK: If you have add methos then you do not need createNewSlide method, instead you can create a new slide and add it to the document, remeber primitivness
    std::shared_ptr<Target> createNewSlide();

    //TK: Find should return iterator
    template <typename TargetType>
    std::shared_ptr<TargetType> findSlideById(const int& slideId) const {
        auto it = std::find_if(slides.begin(), slides.end(),
                               [slideId](const auto& slide) {
                                   return slide->getId() == slideId;
                               });

        return (it != slides.end()) ? std::dynamic_pointer_cast<TargetType>(*it) : nullptr;
    }

    std::shared_ptr<Slide> getActiveSlide() const;

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
