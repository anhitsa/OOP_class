#include "addremoveaction.h"

void AddRemoveAction::execute()
{
    container->addTarget(target);
}

void AddRemoveAction::undo()
{
    container->removeTarget(target);
}
