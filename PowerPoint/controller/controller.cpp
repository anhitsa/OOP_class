#include "controller.h"
#include "../commands/command.h"
#include "../document/slide.h"
#include "../user_interface/application_window.h"

#include <memory>
#include <QApplication>

int Controller::runPowerPointLoop(int argc, char* argv[])
{
    QApplication a(argc, argv);
    ApplicationWindow::initialize();
    ApplicationWindow& appWindow = ApplicationWindow::getInstance();
    appWindow.show();
    Slide slide;

    QObject::connect(&appWindow, &ApplicationWindow::userInputReceived, [this, &slide](const QString& input){
        std::unique_ptr<Command> command = commandParser.parse(input);
        command->execute();
    });

    return a.exec();
}


