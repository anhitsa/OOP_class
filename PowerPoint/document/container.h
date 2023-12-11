#ifndef CONTAINER_H
#define CONTAINER_H

#include "target.h"

//TK: If your intent is to have standardazied interfaced for your container-like classes then it is better to make this template implementation adn derive from it
class Container
{
public:
    virtual ~Container() = default;
    virtual void addTarget(const std::shared_ptr<Target>& target) = 0;
    virtual void removeTarget(const std::shared_ptr<Target>& target) = 0;
};

#endif // CONTAINER_H
