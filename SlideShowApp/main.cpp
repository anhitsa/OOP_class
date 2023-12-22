#include "Application/application.h"

int main(int argc, char *argv[])
{
    std::shared_ptr<Application> application = Application::getInstance(argc, argv);
    application->run();
}
