#ifndef SLIDE_H
#define SLIDE_H

#include "container.h"
#include "target.h"

#include <vector>

//TK: Same interface is here like in doc, you can make your Container template implementation, you will need it also for the GroupItem
class Slide : public Target, public Container<Target>
{
public:
    Slide()=default;
    void add(const std::shared_ptr<Target>&) override;
    void remove(const std::shared_ptr<Target>&) override;
    std::shared_ptr<Target> findItemById(const int&) const;
    void setId(ID);
    const ID& getId() const override;
    std::string getInfo() const override;
    std::vector<std::shared_ptr<Target>> getTargets() const;

private:
    std::vector<std::shared_ptr<Target>> targets;
    ID id; //TK: Actually you do not need id for slodes, root item's Id can serve for slides as well

};

#endif // SLIDE_H
