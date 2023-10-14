#include "exitcommand.h"

void ExitCommand::execute(Slide& slide)
{
    MainWindow::exitApplication();
}
