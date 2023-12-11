#include "controller.h"
#include "../commands/command.h"
#include "../document/document.h"
#include "../document/documentmanager.h"
#include "../user_interface/application_window.h"

#include <memory>
#include <QApplication>

int Controller::runPowerPointLoop(int argc, char* argv[])
{
    //TK: As i told Application is higher level abstraction, Controller, Document & etc are belonging to/instanciated by application, not vice versa 
    QApplication a(argc, argv);
    ApplicationWindow& appWindow = ApplicationWindow::getInstance();
    appWindow.show();

    //TK: Applicatiojn serves as anchor main singletone object, additional singletones not need, they are adding complications
    DocumentManager& manager = DocumentManager::getInstance();
    manager.setDocument(std::make_shared<Document>());

    //TK: UI specific events should be handled by UI itself explicitely, they should not be exposed such way
    QObject::connect(&appWindow, &ApplicationWindow::userInputReceived, [this](const QString& input){
        std::unique_ptr<Command> command = commandParser.parse(input);
        command->execute();
    });

    return a.exec();
}


