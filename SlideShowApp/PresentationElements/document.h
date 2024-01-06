#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "slide.h"

#include <vector>

class Document
{
public:
    Document();
    void add(const std::shared_ptr<Slide>&);
    void remove(const std::shared_ptr<Slide>&);
    Slide::ID getNewSlideId() const;
    std::vector<std::shared_ptr<Slide>>::const_iterator findSlideById(const Slide::ID&) const;
    std::shared_ptr<Slide> getActiveSlide() const;
    void setActiveSlide(const std::shared_ptr<Slide>& slide);
    std::vector<std::shared_ptr<Slide>> getSlides() const;

private:
    std::vector<std::shared_ptr<Slide>> slides;
    std::shared_ptr<Slide> activeSlide;

};
#endif // DOCUMENT_H

