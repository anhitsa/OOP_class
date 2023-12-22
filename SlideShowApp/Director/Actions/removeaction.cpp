#include "removeaction.h"

void RemoveAction::execute()
{
    container->remove(target);
}

void RemoveAction::undo()
{
    container->add(target);
}
