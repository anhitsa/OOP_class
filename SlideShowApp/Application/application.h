#ifndef APPLICATION_H
#define APPLICATION_H

#include "../CommandLineInterface/Controller/controller.h"
#include "../CommandLineInterface/CommandFactory/commandfactory.h"
#include "../ActionHandler/ActionManager/actionmanager.h"
#include "../PresentationElements/document.h"
#include "../UserInterface/applicationwindow.h"
#include "../Serializer/serializer.h"

#include <QApplication>

class Application : public QApplication
{
    Q_OBJECT

public:
    static std::shared_ptr<Application> getInstance(int& argc, char* argv[]);
    static std::shared_ptr<Application> getInstance();
    std::shared_ptr<Controller> getController() const;
    std::shared_ptr<Document> getDocument() const;
    std::shared_ptr<Renderer> getRenderer() const;
    std::shared_ptr<ApplicationWindow> getApplicationWindow() const;
    void exitApplication();
    int run();

private:
    std::shared_ptr<Controller> controller;
    std::shared_ptr<ApplicationWindow> applicationWindow;
    std::shared_ptr<Document> document;
    std::shared_ptr<Renderer> renderer;
    std::shared_ptr<Serializer> serializer;
    std::shared_ptr<ActionManager> actionManager;

private:
    Application(int& argc, char* argv[]);
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

};

#endif // APPLICATION_H
