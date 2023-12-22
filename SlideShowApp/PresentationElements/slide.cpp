#include "slide.h"

#include <memory>

void Slide::setId(ID newId)
{
    id = newId;
}

const Slide::ID& Slide::getId() const
{
    return id;
}

void Slide::add(const std::shared_ptr<Target>& target)
{
    targets.push_back(target);
}

void Slide::remove(const std::shared_ptr<Target>& target)
{
    auto it = std::find(targets.begin(), targets.end(), target);
    if (it != targets.end())
        targets.erase(it);
}

std::shared_ptr<Target> Slide::findItemById(const ID& itemId) const
{
    auto it = std::find_if(targets.begin(), targets.end(),
                           [itemId](const auto& item) {
                               return item->getId() == itemId;
                           });

    return (it != targets.end()) ? *it : nullptr;
}

std::vector<std::shared_ptr<Target>> Slide::getTargets() const
{
    return targets;
}

std::string Slide::getInfo() const
{
    std::string info;
    info += "Slide id: " + std::to_string(id) + "\n";
    for(auto& target : targets)
        info += target->getInfo();
    return info;
}
