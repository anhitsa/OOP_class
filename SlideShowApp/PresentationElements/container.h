#ifndef CONTAINER_H
#define CONTAINER_H

#include <memory>

template <typename T>
class Container
{
public:
    virtual ~Container() = default;

    virtual void add(const std::shared_ptr<T>&) = 0;
    virtual void remove(const std::shared_ptr<T>&) = 0;
};

#endif // CONTAINER_H
