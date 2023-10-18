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

    auto& commandParserRef = commandParser;
    auto& slideRef = slide;

    QObject::connect(&appWindow, &ApplicationWindow::userInputReceived, [&](const QString& input){
        std::unique_ptr<Command> command = commandParserRef.parse(input);
        command->execute(slideRef);
    });

    return a.exec();
}


