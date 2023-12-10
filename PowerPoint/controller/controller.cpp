#include "controller.h"
#include "../commands/command.h"
#include "../document/document.h"
#include "../document/documentmanager.h"
#include "../user_interface/application_window.h"

#include <memory>
#include <QApplication>

int Controller::runPowerPointLoop(int argc, char* argv[])
{
    QApplication a(argc, argv);
    ApplicationWindow& appWindow = ApplicationWindow::getInstance();
    appWindow.show();

    DocumentManager& manager = DocumentManager::getInstance();
    manager.setDocument(std::make_shared<Document>());

    QObject::connect(&appWindow, &ApplicationWindow::userInputReceived, [this](const QString& input){
        std::unique_ptr<Command> command = commandParser.parse(input);
        command->execute();
    });

    return a.exec();
}


