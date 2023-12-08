#ifndef CONTAINER_H
#define CONTAINER_H

#include "target.h"

class Container {
public:
    virtual ~Container() = default;
    virtual void addTarget(const std::shared_ptr<Target>& target) = 0;
    virtual void removeTarget(const std::shared_ptr<Target>& target) = 0;
};

#endif // CONTAINER_H
