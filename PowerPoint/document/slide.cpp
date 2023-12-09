#include "slide.h"

#include <memory>

void Slide::addTarget(const std::shared_ptr<Target>& target) override
{
    targets.push_back(target);
}

void Slide::removeTarget(const std::shared_ptr<Target>& target) override
{
    auto it = std::find(targets.begin(), targets.end(), target);
    if (it != targets.end())
        targets.erase(it);
}

std::shared_ptr<Target> Slide::findItemById(const int& itemId) const
{
    auto it = std::find_if(targets.begin(), targets.end(),
                           [itemId](const auto& item) {
                               return item->id == itemId;
                           });

    return (it != targets.end()) ? *it : nullptr;
}

void Slide::changeParameters(std::unordered_map<std::string, std::string> options)
{

}
