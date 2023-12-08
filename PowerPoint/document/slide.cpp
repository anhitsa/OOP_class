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
