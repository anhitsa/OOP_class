#include "changeaction.h"

void ChangeAction::execute()
{
    target->changeParameters(options);
}

void ChangeAction::undo()
{
    target->undoParametersChange();
}
