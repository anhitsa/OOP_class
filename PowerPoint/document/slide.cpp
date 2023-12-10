#include "slide.h"

#include <memory>

void Slide::setId(int newId)
{
    id = newId;
}

int Slide::getId() const
{
    return id;
}

void Slide::addTarget(const std::shared_ptr<Target>& target)
{
    targets.push_back(target);
}

void Slide::removeTarget(const std::shared_ptr<Target>& target)
{
    auto it = std::find(targets.begin(), targets.end(), target);
    if (it != targets.end())
        targets.erase(it);
}

std::shared_ptr<Target> Slide::findItemById(const int& itemId) const
{
    auto it = std::find_if(targets.begin(), targets.end(),
                           [itemId](const auto& item) {
                               return item->getId() == itemId;
                           });

    return (it != targets.end()) ? *it : nullptr;
}

void Slide::changeParameters(std::map<std::string, std::string> options)
{

}

void Slide::undoParametersChange()
{

}

