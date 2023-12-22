#include "controller.h"

Controller::Controller() : commandLineInputBox(std::make_shared<CommandLineInputBox>()),
    commandLineOutputBox(std::make_shared<CommandLineOutputTerminal>()),
    commandParser()
{
    QObject::connect(commandLineInputBox.get(), &CommandLineInputBox::userInputReceived, [this](const QString& input){
        std::unique_ptr<Command> command = commandParser.parse(input);
        command->execute();
    });
}

std::shared_ptr<CommandLineInputBox> Controller::getCommandLineInputBox() const
{
    return commandLineInputBox;
}

std::shared_ptr<CommandLineOutputTerminal> Controller::getCommandLineOutputBox() const
{
    return commandLineOutputBox;
}

void Controller::setCommandFactory(std::shared_ptr<CommandFactory> factory)
{
    commandFactory = factory;
}

std::shared_ptr<CommandFactory> Controller::getCommandFactory() const
{
    return commandFactory;
}
