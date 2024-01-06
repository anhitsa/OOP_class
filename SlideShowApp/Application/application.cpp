#include "application.h"

Application::Application(int& argc, char* argv[])
    : QApplication(argc, argv),
    controller(std::make_shared<Controller>()),
    applicationWindow(std::make_shared<ApplicationWindow>(controller->getCommandLineInputBox(), controller->getCommandLineOutputBox())),
    document(std::make_shared<Document>()),
    renderer(std::make_shared<Renderer>(applicationWindow)),
    serializer(std::make_shared<Serializer>()),
    actionManager(std::make_shared<ActionManager>())
{
    controller->setCommandFactory(std::make_shared<CommandFactory>(document, renderer, serializer, actionManager));
    connect(applicationWindow->getUndoButton(), &QPushButton::clicked, actionManager.get(), &ActionManager::undo);
    connect(applicationWindow->getRedoButton(), &QPushButton::clicked, actionManager.get(), &ActionManager::redo);
}

std::shared_ptr<Application> Application::getInstance(int& argc, char* argv[])
{
    static std::shared_ptr<Application> instance = std::shared_ptr<Application>(new Application(argc, argv));
    return instance;
}

std::shared_ptr<Application> Application::getInstance()
{
    int default_argc = 0;
    char* default_argv[] = { nullptr };
    return getInstance(default_argc, default_argv);
}

std::shared_ptr<Controller> Application::getController() const
{
    return controller;
}

std::shared_ptr<Document> Application::getDocument() const
{
    return document;
}

std::shared_ptr<Renderer> Application::getRenderer() const
{
    return renderer;
}

std::shared_ptr<ApplicationWindow> Application::getApplicationWindow() const
{
    return applicationWindow;
}

int Application::run()
{
    return exec();
}

void Application::exitApplication()
{
    applicationWindow->exitApplicationWindowWithMessage();
    QApplication::quit();
}
