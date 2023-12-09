#ifndef ADDREMOVEACTION_H
#define ADDREMOVEACTION_H

#include "commandaction.h"
#include "../document/container.h"
#include "../document/target.h"

#include <memory>

class AddRemoveAction : public CommandAction
{
public:
    AddRemoveAction(std::shared_ptr<Target> target, std::shared_ptr<Container> container)
        : target(target), container(container) {}

    void execute() override;
    void undo() override;

private:
    std::shared_ptr<Target> target;
    std::shared_ptr<Container> container;

};


#endif // ADDREMOVEACTION_H
