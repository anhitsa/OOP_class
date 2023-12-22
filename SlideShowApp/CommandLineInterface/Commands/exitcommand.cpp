#include "exitcommand.h"

void ExitCommand::execute()
{
    std::shared_ptr<Application> application = Application::getInstance();
    application->exit();
}
