#include "changeaction.h"

void ChangeAction::execute()
{
    target->changeParameters(options);
}
