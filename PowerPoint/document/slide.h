#ifndef SLIDE_H
#define SLIDE_H

#include "container.h"
#include "target.h"
#include "item.h"

#include <vector>


class Slide : public Target, public Container
{
public:
    Slide()=default;
    void addTarget(const std::shared_ptr<Target>&) override;
    void removeTarget(const std::shared_ptr<Target>&) override;
    void changeParameters(std::map<std::string, std::string> options) override;
    void undoParametersChange() override;
    std::shared_ptr<Target> findItemById(const int&) const;
    void setId(int);
    int getId() const override;

public:
    std::vector<std::shared_ptr<Target>> targets;

private:
    int id;

};

#endif // SLIDE_H
