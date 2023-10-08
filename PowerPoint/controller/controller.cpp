#include "controller.h"
#include "../commands/command.h"
#include "../document/slide.h"
#include "../user_interface/mainwindow.h"

#include <memory>
#include <QApplication>

int Controller::runPowerPointLoop(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Slide slide;

    auto& commandParserRef = commandParser;
    auto& slideRef = slide;

    QObject::connect(&w, &MainWindow::userInputReceived, [&w, &commandParserRef, &slideRef](const QString& input) {
        std::istringstream stream(input.toStdString());
        std::unique_ptr<Command> command = commandParserRef.parse(stream);
        command->execute(slideRef);
        //w.printToScreen(slideRef);
    });

    return a.exec();
}

