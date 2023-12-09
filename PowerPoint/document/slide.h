#ifndef SLIDE_H
#define SLIDE_H

#include "container.h"
#include "target.h"

#include <vector>


class Slide : public Target, public Container
{
public:
    Slide()=default;
    void addTarget(const std::shared_ptr<Target>&) override;
    void removeTarget(const std::shared_ptr<Target>&) override;
    void changeParameters(std::unordered_map<std::string, std::string> options) override;

private:
    std::vector<std::shared_ptr<Target>> targets;

};

#endif // SLIDE_H
