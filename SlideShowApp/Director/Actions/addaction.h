#ifndef ADDACTION_H
#define ADDACTION_H

#include "commandaction.h"
#include "../../PresentationElements/container.h"
#include "../../PresentationElements/target.h"

#include <memory>

class AddAction : public CommandAction
{
public:
    AddAction(std::shared_ptr<Target> target, std::shared_ptr<Container<Target>> container)
        : target(target), container(container) {}

    void execute() override;
    void undo() override;

private:
    std::shared_ptr<Target> target;
    std::shared_ptr<Container<Target>> container;
    //TK: here you also need the position to restore target in its original position

};


#endif // ADDACTION_H
