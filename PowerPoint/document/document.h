#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "container.h"
#include "slide.h"

#include <vector>

class Document : public Container
{
public:
    static Document& getInstance();
    void addTarget(const std::shared_ptr<Target>&) override;
    void removeTarget(const std::shared_ptr<Target>&) override;
    void setActiveSlide(const std::shared_ptr<Target>& slide);
    std::shared_ptr<Target> getActiveSlide() const;
    std::shared_ptr<Target> findSlideById(const ID& slideId) const;
    std::shared_ptr<Target> createNewSlide();

private:
    Document() = default;
    Document(const Document&) = delete;
    Document& operator=(const Document&) = delete;

private:
    std::vector<std::shared_ptr<Target>> slides;
    std::shared_ptr<Slide> activeSlide;

};
#endif // DOCUMENT_H
