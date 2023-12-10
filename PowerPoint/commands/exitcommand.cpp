#include "exitcommand.h"

ExitCommand::ExitCommand(std::map<std::string, std::string> options)
    : options(options) {}

void ExitCommand::execute()
{
    ApplicationWindow::exitApplication();
}
