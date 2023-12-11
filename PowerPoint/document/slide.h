#ifndef SLIDE_H
#define SLIDE_H

#include "container.h"
#include "target.h"
#include "item.h"

#include <vector>

//TK: Same interface is here like in doc, you can make your Container template implementation, you will need it also for the GroupItem
class Slide : public Target, public Container
{
public:
    Slide()=default;
    void addTarget(const std::shared_ptr<Target>&) override;
    void removeTarget(const std::shared_ptr<Target>&) override;

    //TK: What is this method for, do slide have parameters?
    void changeParameters(std::map<std::string, std::string> options) override;
    //TK: Undo is not method of the slide either
    void undoParametersChange() override;
    std::shared_ptr<Target> findItemById(const int&) const;
    void setId(int);
    int getId() const override;

public:
    //TK: should be private
    std::vector<std::shared_ptr<Target>> targets;

private:
    int id; //TK: Actually you do not need id for slodes, root item's Id can serve for slides as well

};

#endif // SLIDE_H
