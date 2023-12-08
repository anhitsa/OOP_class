#ifndef ADDREMOVEACTION_H
#define ADDREMOVEACTION_H

#include "commandaction.h"
#include "../document/target.h"

#include <memory>

class AddRemoveAction : public CommandAction
{
private:
    std::shared_ptr<Target> target;
    std::shared_ptr<Container> container;

public:
    AddRemoveAction(std::shared_ptr<Target> target, std::shared_ptr<Container> container)
        : target(target), container(container) {}

    void execute() override
    {
        container->addTarget(target);
    }

    void undo() override
    {
        container->removeTarget(target);
    }
};


#endif // ADDREMOVEACTION_H
