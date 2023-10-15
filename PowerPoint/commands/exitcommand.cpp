#include "exitcommand.h"

void ExitCommand::execute(Slide& slide)
{
    ApplicationWindow::exitApplication();
}
