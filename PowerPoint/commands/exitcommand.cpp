#include "exitcommand.h"

ExitCommand::ExitCommand(std::map<std::string, std::string> options)
    : options(options) {}

void ExitCommand::execute()
{
    //TK: need to call Application::instance()->exit() instead, if it is GUI app then it will take care for windos 
    ApplicationWindow::exitApplication();
}
