#ifndef REMOVEACTION_H
#define REMOVEACTION_H

#include "commandaction.h"
#include "../../PresentationElements/container.h"
#include "../../PresentationElements/target.h"

#include <memory>

class RemoveAction : public CommandAction
{
public:
    RemoveAction(std::shared_ptr<Target> target, std::shared_ptr<Container<Target>> container)
        : target(target), container(container) {}

    void execute() override;
    void undo() override;

private:
    std::shared_ptr<Target> target;
    std::shared_ptr<Container<Target>> container;

};

#endif // REMOVEACTION_H
