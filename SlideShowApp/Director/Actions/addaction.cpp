#include "addaction.h"

void AddAction::execute()
{
    container->add(target);
}

void AddAction::undo()
{
    container->remove(target);
}
